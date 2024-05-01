// WHicks_MapsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "schedule.h"
using namespace std;

//Hash function, activated when given a key
size_t schedHash(string key)
{
    int hashVal = 0;

    //Provided Funct. 1:
    //for (char ch : key)
    //    hashVal += ch;

    //Provided Funct. 2:
    //hashVal = key[0] + 27 * key[1] + 729 * key[2];

    //Provided Funct. 3
    //for (char ch : key)
    //    hashVal = 37 * hashVal + ch;
    // ** is unsigned

    //Custom function:
    for (int keyI = 0; keyI < 3; keyI++)
        for (char ch : key)
            hashVal = 37 * hashVal + 27 * key[keyI] + 270 * key[keyI + 4] + 9990 * key[keyI + 8] + ch;

    return hashVal;
}

//Main function
int main()
{
    schedule newSched(179);
    newSched.setHashFunction(schedHash);
    newSched.initSchedule();
    //newSched.statistics();

    int input = 0;

    while (input < 6)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "Welcome to Main Menu Mode. May I take your order?" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1 : Search by subject" << endl;
        cout << "2 : Search by subject AND catalog" << endl;
        cout << "3 : Search by last name of instructor" << endl;
        cout << "4 : Print every course" << endl;
        cout << "5 : Print statistics" << endl;
        cout << "6 : Print the bucket number, given a key" << endl;
        cout << "7+: Get out of this program" << endl << endl;
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
            string searchKey = sub + "_" + cat + "_" + sect;
            int hashVal = schedHash(searchKey);
            int hashIndex = hashVal % newSched.getSize();
            if (hashIndex >= 0)
                cout << "Key found in Bucket " << hashIndex << endl;
            else
                cout << "Key not found." << endl;
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
