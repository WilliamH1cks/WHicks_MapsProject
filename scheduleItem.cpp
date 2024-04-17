#include "scheduleItem.h"
#include <iostream>
using namespace std;

void scheduleItem::setItemKey()
{
	key = subject + "_" + catalog + "_" + section;
	return;
}

bool scheduleItem::operator==(scheduleItem right)
{
	return (key == right.key);
}
bool scheduleItem::operator!=(scheduleItem right)
{
	return (key != right.key);
}
bool scheduleItem::operator>=(scheduleItem right)
{
	return (key >= right.key);
}

void scheduleItem::print()
{
	cout << subject << "       " << catalog << "   " << section << "   " << component << "   " << session << "     " << units << "        " 
		<< totEnrl << "                " << capEnrl << "   " << instructor << endl;
	return;
}