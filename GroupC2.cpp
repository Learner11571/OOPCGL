#include <iostream>
#include <map>
using namespace std;

int main() {
    string country;
    int population;
    char ans = 'y';
    int choice;
    map<string, int> m;
    map<string, int>::iterator i;

    do {
        cout << "\nMain Menu";
        cout << "\n1. Insert an element";
        cout << "\n2. Display";
        cout << "\n3. Search a state";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the name of state: ";
                cin >> country;
                cout << "\nEnter the population (in Cr): ";
                cin >> population;
                m.insert(pair<string, int>(country, population));
                break;

            case 2:
                cout << "\nState and Populations are: ";
                for (i = m.begin(); i != m.end(); i++) {
                    cout << "[" << (*i).first << ", " << (*i).second << "] ";
                }
                cout << endl;
                break;

            case 3:
                cout << "\nEnter the name of state for searching its population: ";
                cin >> country;
                if (m.count(country) != 0) {
                    cout << "Population is " << m.find(country)->second << " Cr" << endl;
                } else {
                    cout << "State is not present in the list" << endl;
                }
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}
