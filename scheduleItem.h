#pragma once
#include <string>
using namespace std;

class scheduleItem
{
public:
	//Get functioins for each instance variable.
	string getSubject() { return subject; }
	string getCatalog() { return catalog; }
	string getSection() { return section; }
	string getComponent() { return component; }
	string getSession() { return session; }
	int getUnits() { return units; }
	int getTotEnrl() { return totEnrl; }
	int getCapEnrl() { return capEnrl; }
	string getInstructor() { return instructor; }

	//Create key
	void setItemKey();

	//Fetch key
	string getItemKey() { return key; }
	
	//Overloaded ==, !=, and >= operators
	bool operator==(scheduleItem right);
	bool operator!=(scheduleItem right);
	bool operator>=(scheduleItem right);

	//Print function
	void print();

	//Constructor
	scheduleItem(string sub = "", string cat = "", string sect = "", string comp = "", string sess = "", int u = 0, int tE = 0, int cE = 0, string instr = "")
	{
		subject = sub;
		catalog = cat;
		section = sect;
		component = comp;
		session = sess;
		units = u;
		totEnrl = tE;
		capEnrl = cE;
		instructor = instr;

		setItemKey();
	}

private:
	string subject;
	string catalog;
	string section;
	string component;
	string session;
	int units;
	int totEnrl;
	int capEnrl;
	string instructor;
	
	string key;
};

//For some reason this file refused to go onto Github. This comment is meant exclusively to help remedy that.

