#include <iostream>
#include <string>
#include <ostream>

using namespace std;

int main()
{
    string question = "Press 1";
    int choice = 0;

    cout << "Select the number of the term for each definition (0 to exit)\n" << endl;
    cout << "1) Class " << endl;
    cout << "2) Instance " << endl;
    cout << "3) Object " << endl;
    cout << "4) Attribute " << endl;
    cout << "5) Constructor " << endl;
    cout << "6) Destructor " << endl;
    cout << "7) Method " << endl;
    cout << "8) Override " << endl;
    cout << "9) Declaration " << endl;
    cout << "10) Exception \n" << endl;

    cout << question << ": "<< endl;

    cin >> choice;

    switch (choice)
    {
        case 0:
            cout<<"Exiting..." << endl;
            break;

        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            break;
    }
}

