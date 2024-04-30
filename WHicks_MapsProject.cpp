// WHicks_MapsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "schedule.h"
using namespace std;

int findHashIndex(string sub, string cat, string sect, schedule newSched)
{
    string searchKey = sub + "_" + cat + "_" + sect;
    for (int hashIndex = 0; hashIndex < newSched.getSize(); hashIndex++)
    {
        vector<scheduleItem> tempVect = newSched.getBucket(hashIndex);
        if(tempVect.size() != 0)
            if (tempVect[0].getItemKey() == searchKey)
                return hashIndex;
    }
    return -1;
}

int main()
{
    schedule newSched(63);
    newSched.initSchedule();

    int input = 0;

    while (input < 6)
    {
        cout << endl << "Welcome to Main Menu Mode. May I take your order?" << endl;
        cout << "1 : Search by subject" << endl;
        cout << "2 : Search by subject AND catalog" << endl;
        cout << "3 : Search by last name of instructor" << endl;
        cout << "4 : Print every course" << endl;
        cout << "5 : Print statistics" << endl;
        cout << "6 : Print the bucket number, given a key" << endl;
        cout << "7 or more : Get out" << endl;
        cin >> input;

        if (input == 1 || input == 2)
        {
            string sub = "";
            cout << "What is the three-letter abbriviation for subject? ";
            cin >> sub;
            if (input == 1)
                newSched.findSubject(sub);
            else
            {
                string cat = "";
                cout << "What is the Category? (Format is typically 3-digit number) ";
                cin >> cat;
                newSched.findSubject(sub, cat);
            }
        }
        else if (input == 3)
        {
            string name = "";
            cout << "What is the instructor's last name? ";
            cin >> name;
            newSched.findInstructor(name);
        }
        else if (input == 4)
        {
            cout << "okay fine here's everything" << endl;
            newSched.print();
        }
        else if (input == 5)
        {
            cout << "Printing stats..." << endl << endl;
            newSched.statistics();
        }
        else if (input == 6)
        {
            string sub = "";
            cout << "What is the three-letter abbriviation for subject? ";
            cin >> sub;
            string cat = "";
            cout << "What is the Category? (Format is typically 3-digit number) ";
            cin >> cat;
            string sect = "";
            cout << "What is the Section Number? (It may include uppercase letters) ";
            cin >> sect;
            int hashIndex = findHashIndex(sub, cat, sect, newSched);
            cout << "Key found in Bucket " << hashIndex << endl;
        }
        else
        {
            cout << "Then we're done here. Bye." << endl;
        }
    }

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
