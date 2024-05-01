#include "schedule.h"
#include <iostream>
#include <utility>
using namespace std;

void schedule::initSchedule()
{
	ifstream inFile;
	string sub = "", cat = "", sect = "", comp = "", sess = "", instr = "";
	int u = 0, tE = 0, cE = 0;

	string trash = "";

	inFile.open("scheduleFile.csv");
	if (!inFile)
		cout << "File doesn't exist." << endl;
	getline(inFile, trash);
	//cout << trash;
	for (int i = 0; i < 174; i++)
	{
		string unitString = "0";
		string tEString = "0";
		string cEString = "0";

		getline(inFile, sub, ',');
		getline(inFile, cat, ',');
		getline(inFile, sect, ',');
		getline(inFile, comp, ',');
		getline(inFile, sess, ',');
		getline(inFile, trash, ','); //minUnits is not needed
		getline(inFile, unitString, ',');
		getline(inFile, tEString, ',');
		getline(inFile, cEString, ',');
		getline(inFile, trash, ','); //acadOrg is not needed
		getline(inFile, trash, '"'); //removing the quotes from the instructor names
		getline(inFile, instr, '"');
		//cout << instr << endl;
		getline(inFile, trash);

		//cout << "This is a test. Press a key then enter.";
		//cin >> trash;

		u = stoi(unitString);
		tE = stoi(tEString);
		cE = stoi(cEString);

		scheduleItem course(sub, cat, sect, comp, sess, u, tE, cE, instr);
		//course.setItemKey();
		string key = getItemKey(course);
		//pair<string, scheduleItem> newCourse(key, course);
		//course.print();
		schedTable.insert(key, course);
	}

	inFile.close();
	//schedTable.display();
	//print();
}

void schedule::print()
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	//map<string, schedule>::iterator it;
	for (int hashIndex = 0; hashIndex < schedTable.getSize(); hashIndex++)
	{
		vector<scheduleItem> tempVect = schedTable.getByIndex(hashIndex);
		for (int vectIndex = 0; vectIndex < tempVect.size(); vectIndex++)
			tempVect[vectIndex].print();
		cout << endl;
	}
}

void schedule::findSubject(string sub)
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	//for (auto& mapEntry : schedMap)
	//{
	//	if (mapEntry.second.getSubject() == sub)
	//		mapEntry.second.print();
	//}
	for (int hashIndex = 0; hashIndex < schedTable.getSize(); hashIndex++)
	{
		vector<scheduleItem> tempVect = schedTable.getByIndex(hashIndex);
		for (int vectIndex = 0; vectIndex < tempVect.size(); vectIndex++)
			if (tempVect[vectIndex].getSubject() == sub)
				tempVect[vectIndex].print();
	}
}

void schedule::findSubject(string sub, string cat)
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	//for (auto& mapEntry : schedMap)
	//{
	//	if (mapEntry.second.getSubject() == sub)
	//		if (mapEntry.second.getCatalog() == cat)
	//			mapEntry.second.print();
	//}
	for (int hashIndex = 0; hashIndex < schedTable.getSize(); hashIndex++)
	{
		vector<scheduleItem> tempVect = schedTable.getByIndex(hashIndex);
		for (int vectIndex = 0; vectIndex < tempVect.size(); vectIndex++)
			if (tempVect[vectIndex].getSubject() == sub)
				if(tempVect[vectIndex].getCatalog() == cat)
					tempVect[vectIndex].print();
	}
}

void schedule::findInstructor(string instr)
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	for (int hashIndex = 0; hashIndex < schedTable.getSize(); hashIndex++)
	{
		vector<scheduleItem> tempVect = schedTable.getByIndex(hashIndex);
		for (int vectIndex = 0; vectIndex < tempVect.size(); vectIndex++)
		{
			string name = tempVect[vectIndex].getInstructor();
			char* namePtr = new char[name.length() + 1];
			strcpy_s(namePtr, name.length() + 1, name.c_str());

			int index = 0;
			string lastName = "";
			while (index < sizeof(namePtr))
			{
				char currentChar = namePtr[index];
				if (currentChar != ',')
				{
					lastName += currentChar;
					index++;
				}
				else
					index = sizeof(namePtr);
			}
			//cout << lastName << " Test" << endl;

			if (lastName == instr)
				tempVect[vectIndex].print();
		}
	}
}

void schedule::setHashFunction(std::function<size_t(const string&)> hashFunc)
{
	schedTable.setHashFunction(hashFunc);
	return;
}

void schedule::statistics()
{
	cout << "Stats:" << endl;
	cout << "Size of hash table: " << schedTable.getSize() << endl;
	cout << "Number of buckets: " << schedTable.getBuckets() << endl;
	cout << "Load factor: " << schedTable.getLoadFactor() << endl;
	cout << "Number of collisions: " << schedTable.countCollisions() << endl;
	cout << "Length of longest chain: " << schedTable.maxBucketSize() << endl;
	return;
}

int schedule::getSize()
{
	return schedTable.getSize();
}

string schedule::getItemKey(scheduleItem item)
{
	return item.getItemKey();
}