#include "scheduleItem.h"
#include <iostream>
using namespace std;

string scheduleItem::getItemKey()
{
	string key = subject + "_" + catalog + "_" + section;
	return key;
}

bool scheduleItem::operator==(scheduleItem right)
{
	return (getItemKey() == right.getItemKey());
}
bool scheduleItem::operator!=(scheduleItem right)
{
	return (getItemKey() != right.getItemKey());
}
bool scheduleItem::operator>=(scheduleItem right)
{
	return (getItemKey() >= right.getItemKey());
}

void scheduleItem::print()
{
	cout << subject << "       " << catalog << "   " << section << "   " << component << "   " << session << "     " << units << "        " 
		<< totEnrl << "                " << capEnrl << "   " << instructor << endl;
	return;
}