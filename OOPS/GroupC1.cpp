#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct rec {
    char name[20];
    char BirthDt[20];
    char phone[11];
} node;

node temp;
vector<node> rec; // create an empty vector

bool compare(node &r1, node &r2) {
    if (strcmp(r1.name, r2.name) < 0)
        return true;
    return false;
}

void Create() {
    int n, i;
    cout << "\nHow many elements do you want to insert?" << endl;
    cin >> n;
    cout << "\nEnter the elements in the database" << endl;
    
    for (i = 0; i < n; i++) {
        cout << "\nName: ";
        cin >> temp.name;
        cout << "\nBirth Date (dd-mm-yy): ";
        cin >> temp.BirthDt;
        cout << "\nPhone: ";
        cin >> temp.phone;
        rec.push_back(temp);
    }
}

void Display() {
    cout << "\nDisplaying the database: " << endl;
    for (auto &r : rec) {
        cout << "\nName: " << r.name
             << "\nBirth Date: " << r.BirthDt
             << "\nPhone: " << r.phone << endl;
    }
}

void Searching() {
    char searchName[20];
    cout << "\nEnter the name to search: ";
    cin >> searchName;
    
    bool found = false;
    for (auto &r : rec) {
        if (strcmp(r.name, searchName) == 0) {
            cout << "\nRecord found: "
                 << "\nName: " << r.name
                 << "\nBirth Date: " << r.BirthDt
                 << "\nPhone: " << r.phone << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\nRecord not found!" << endl;
    }
}

void Sorting() {
    sort(rec.begin(), rec.end(), compare);
    cout << "\nDatabase sorted by name." << endl;
}

int main() {
    char ans;
    int choice;
    
    do {
        cout << "\nMain Menu";
        cout << "\n1. Create a database";
        cout << "\n2. Display the database";
        cout << "\n3. Search a particular element";
        cout << "\n4. Sort the database (based on name)";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Searching();
                break;
            case 4:
                Sorting();
                Display();
                break;
            default:
                cout << "\nInvalid choice!" << endl;
        }
        
        cout << "\nDo you want to go back to the Main Menu? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    
    return 0;
}
