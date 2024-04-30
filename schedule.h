#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <functional>
#include "scheduleItem.h"
using namespace std;

class schedule
{
public:
	//Makes the schedule
	void initSchedule();

	//Prints schedule
	void print();

	//Finds records w/ target subject
	void findSubject(string);
	//Finds records w/ target subject, catalog
	void findSubject(string, string);
	//Finds records w/ target instrctor
	void findInstructor(string);

	//Precond: Recieves pointer to user-defined hash funct
	//Postcond: Sets hash function in table to user-defined function
	void setHashFunction(function<size_t(const string&)>);
	
	//Postcond: Displays stats, including:
	//	- Size of hash; - # of buckets
	//	- Load factor;  - # # collisions
	//	- Length of longest chain
	void statistics();

	//Fetches the size of the schedule's hash table
	int getSize();

	//Fetches a bucket in the hash table
	vector<scheduleItem> getBucket(int index);

	//Schedule Consrtuctor
	schedule(int size) : schedTable(size)
	{
	};

private:
	//map<string, scheduleItem> schedMap;
	HashTable<string, scheduleItem> schedTable;
};