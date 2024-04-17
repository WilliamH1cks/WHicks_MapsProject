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
		getline(inFile, trash, '"'); //removing teh quotes from the instructor names
		getline(inFile, instr, '"');
		//cout << instr << endl;
		getline(inFile, trash);

		//cout << "This is a test. Press a key then enter.";
		//cin >> trash;

		u = stoi(unitString);
		tE = stoi(tEString);
		cE = stoi(cEString);

		scheduleItem course(sub, cat, sect, comp, sess, u, tE, cE, instr);
		string key = course.getItemKey();
		pair<string, scheduleItem> newCourse(key, course);
		//course.print();
		schedMap.insert(newCourse);
	}

	inFile.close();
	//print();
}

void schedule::print()
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	//map<string, schedule>::iterator it;
	for (auto &mapEntry : schedMap)
	{
		mapEntry.second.print();
	}
}

void schedule::findSubject(string sub)
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	for (auto& mapEntry : schedMap)
	{
		if (mapEntry.second.getSubject() == sub)
			mapEntry.second.print();
	}
}

void schedule::findSubject(string sub, string cat)
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	for (auto& mapEntry : schedMap)
	{
		if (mapEntry.second.getSubject() == sub)
			if (mapEntry.second.getCatalog() == cat)
				mapEntry.second.print();
	}
}

void schedule::findInstructor(string instr)
{
	cout << "Subject: " << "/Cat: " << "/Sect: "
		<< "/Comp:" << "/Sess: " << "/Units " << "/Total Enrolled: " <<
		"/Max Enroll: " << "/Instructor: " << endl;
	for (auto& mapEntry : schedMap)
	{
		string name = mapEntry.second.getInstructor();
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
			mapEntry.second.print();
	}
}