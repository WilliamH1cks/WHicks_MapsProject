#include <map>
#include <iostream>
#include <fstream>
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

private:
	map<string, scheduleItem> schedMap;
};