// WHicks_MapsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "schedule.h"
using namespace std;

int main()
{
    schedule newSched;
    newSched.initSchedule();

    int input = 0;

    while (input < 6)
    {
        cout << "Welcome to Main Menu Mode. May I take your order?" << endl;
        cout << "1 : Search by subject (lame)" << endl;
        cout << "2 : Search by subject AND catalog (daring today, are we?)" << endl;
        cout << "3 : Search by last name of instructor (epic choice)" << endl;
        cout << "4 : Type four if you just want me to print everything" << endl;
        cout << "5 : Get out" << endl;
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
            cout << "okay fine here's everything";
            newSched.print();
        }
        else
        {
            cout << "Okay, we're done here then. Bye." << endl;
            return 0;
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
