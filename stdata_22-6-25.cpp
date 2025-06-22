#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
bool check_roll(string rolls){
	string  roll ,name , father , gender , blood;
	
	ifstream inFile("students.txt");
	while(inFile >> roll >> name >> father >> gender >> blood){
		if(roll==rolls){
			cout<<"roll no already exist";
			return true;
		}
	}
	inFile.close();
	return false;
	}


int main() {
	menu:
    int choice;

    cout << "Welcome to Student Record System\n";
    cout << "Press 1 to Save New Student Data\n";
    cout << "Press 2 to Search Student by Roll Number\n";
    cout << "Press 3 to Display All Student Data\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // OPTION 1: SAVE STUDENTS TO FILE
        ofstream outFile("students.txt",ios::app); // append mode

        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return 1;
        }

        int again=0;
        student_save:
        
        for (int i = 0; i < 1; i++) {
            string roll, name, father, gender, blood;
            string againMsg="";
            if(again==1)
              againMsg=" again please ";
            cout << "\nEnter data for student " <<againMsg<< i + 1 << ":\n";

            cout << "Roll Number: ";
            cin >> roll;
            bool answer=check_roll(roll);
            if(answer==true)
            {
            	system("cls");
            	cout<<"roll number already exist";
            	 again=1;
            	goto student_save;
            	
			}
            cout << "Name: ";
            cin >> name;
            cout << "Father Name: ";
            cin >> father;
            cout << "Gender: ";
            cin >> gender;
            cout << "Blood Group: ";
            cin >> blood;

            outFile << roll << " " << name << " " << father << " " << gender << " " << blood << endl;
        }

        outFile.close();
        cout << "\nStudent data saved successfully.\n";
        system("cls");
        goto menu;
    }
    

    else if (choice == 2) {
        // OPTION 2: SEARCH BY ROLL NUMBER
        ifstream inFile("students.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string searchRoll;
        cout << "Enter Roll Number to search: ";
        cin >> searchRoll;

        string roll, name, father, gender, blood;
        int found = 0;

        while (inFile >> roll >> name >> father >> gender >> blood) {
            if (roll == searchRoll) {
                cout << "\nStudent Found:\n";
                cout << "Roll Number: " << roll << endl;
                cout << "Name: " << name << endl;
                cout << "Father Name: " << father << endl;
                cout << "Gender: " << gender << endl;
                cout << "Blood Group: " << blood << endl;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            cout << "Invalid Roll Number\n";
        }

        inFile.close();
         system("cls");
        goto menu;
    }

    else if (choice == 3) {
        // OPTION 3: DISPLAY ALL DATA
        ifstream inFile("students.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string roll, name, father, gender, blood;

        cout << "\nAll Student Data:\n";
        cout << "RollNo\tName\tF_Name\tGender\tBlood\n";

        while (inFile >> roll >> name >> father >> gender >> blood) {
            cout << roll << "\t" << name << "\t" << father << "\t" << gender << "\t" << blood << endl;
        }

        inFile.close();
    }

    else {
        cout << "Invalid choice. Please run the program again.\n";
         system("cls");
        goto menu;
    }

    return 0;
}

