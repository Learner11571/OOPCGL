#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class PersonClass
{
private:
    char name[40], clas[10], div[2], dob[15], bloodgrp[5];
    int roll;

public:
    static int count; // static data
    friend class PersonnelClass;
    
    // Constructor
    PersonClass()
    {
        strcpy(name, "");  // Initialize the string with empty values
        strcpy(dob, "");
        strcpy(bloodgrp, "");
        strcpy(clas, "");
        strcpy(div, "");
        roll = 0;
        count++;  // Increment static count here
    }

    // Static method
    static void TotalRecordCount()
    {
        cout << "\n\n\nTOTAL NUMBER OF RECORDS CREATED: " << count;
    }
};

class PersonnelClass
{
private:
    char address[30], telephone_no[15], policy_no[10], license_no[10];

public:
    // Constructor
    PersonnelClass()
    {
        strcpy(address, "");  // Initialize with empty strings
        strcpy(telephone_no, "");
        strcpy(policy_no, "");
        strcpy(license_no, "");
    }

    // Methods to input and display data
    void InputData(PersonClass *obj);
    void DisplayData(PersonClass *obj);
    friend class PersonClass;
};

// Initialize static variable
int PersonClass::count = 0;

// Input Data method
void PersonnelClass::InputData(PersonClass *obj)
{
    cout << "\nROLLNO: ";
    cin >> obj->roll;
    cin.ignore();  // Clear the input buffer

    cout << "\nNAME: ";
    cin.getline(obj->name, 40);  // Use getline for strings with spaces

    cout << "\nCLASS: ";
    cin.getline(obj->clas, 10);

    cout << "\nDIVISION: ";
    cin.getline(obj->div, 2);

    cout << "\nDATE OF BIRTH (DD-MM-YYYY): ";
    cin.getline(obj->dob, 15);

    cout << "\nBLOOD GROUP: ";
    cin.getline(obj->bloodgrp, 5);

    cout << "\nADDRESS: ";
    cin.getline(this->address, 30);

    cout << "\nTELEPHONE NUMBER: ";
    cin.getline(this->telephone_no, 15);

    cout << "\nDRIVING LICENSE NUMBER: ";
    cin.getline(this->license_no, 10);

    cout << "\nPOLICY NUMBER: ";
    cin.getline(this->policy_no, 10);
}

// Display Data method
void PersonnelClass::DisplayData(PersonClass *obj)
{
    cout << "\n" << obj->roll << " "
         << obj->name << " "
         << obj->clas << " "
         << obj->div << " "
         << obj->dob << " "
         << this->address << " "
         << this->telephone_no << " "
         << obj->bloodgrp << " "
         << this->license_no << " "
         << this->policy_no;
}

int main()
{
    PersonnelClass *a[10];
    PersonClass *c[10];
    int n = 0, i, choice;
    char ans;

    do
    {
        cout << "\n\nMENU: ";
        cout << "\n\t1. Input Data\n\t2. Display Data";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the input buffer after cin

        switch (choice)
        {
        case 1:
            cout << "\n\n\tENTER THE DETAILS";
            cout << "\n------------------------------";  // Use regular dashes here
            do
            {
                a[n] = new PersonnelClass;
                c[n] = new PersonClass;
                a[n]->InputData(c[n]);
                n++;
                PersonClass::TotalRecordCount();
                cout << "\n\nDo you want to add more records? (y/n): ";
                cin >> ans;
                cin.ignore();  // Clear the input buffer
            } while (ans == 'y' || ans == 'Y');
            break;

        case 2:
            cout << "\n--------------------------------";
            cout << "\nRoll Name Class Div BirthDate Address Telephone Blood_Gr Licence Policy";
            cout << "\n--------------------------------";
            for (i = 0; i < n; i++)
                a[i]->DisplayData(c[i]);
            PersonClass::TotalRecordCount();
            break;
        }

        cout << "\n\nDo you want to go to main menu? (y/n): ";
        cin >> ans;
        cin.ignore();  // Clear the input buffer
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
