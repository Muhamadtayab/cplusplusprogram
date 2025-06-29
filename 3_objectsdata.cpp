#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
bool checkcnic(string num){
	string cnic;
	ifstream inFile("owner.txt");
	while(inFile>>cnic){
		if(cnic==num){
			return true;
		}
	}
	inFile.close();
	return false;
}

bool check_flat(string flat_num){
	string flat;
	ifstream inFile("flat.txt");
	while(inFile>>flat){
		if(flat_num==flat){
			return true;
		}
	}
	inFile.close();
	return false;
}

bool check_chasis(string chasis_num){
	string chasis;
	ifstream inFile("car.txt");
	while(inFile>>chasis){
		if(chasis_num==chasis){
			return true;
		}
	}
	inFile.close();
	return false;
}


int main() {
	int choices;
	cout<<"(----Flat Menu----)\n";
	cout << "Press 1 to add owner data\n";
    cout << "Press 2 to add flat data\n";
    cout << "Press 3 to add cars data\n";
    cout << "Enter your choice: ";
    cin >> choices;
    
    cout<<endl;
    system("cls");
    if(choices==1){
    	owner:
    int choice;

    cout << "(----owner data----)\n";
    cout << "Press 1 to Save owner Data\n";
    cout << "Press 2 to Search owner by CNIC\n";
    cout << "Press 3 to Display All owner Data\n";
    
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
    	menu:
       
        ofstream outFile("owner.txt",ios::app); // append mode

        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return 1;
        }
        
        string cnic,name,contact;

        cout<<"Enter CNIC:";
        cin>>cnic;
       if(checkcnic(cnic)==true){
       		system("cls");
       	cout<<"CNIC already exist plz change CNIC No."<<endl;
       
       	
       
       
       		goto menu;
       		return false;
	   }
	   
        cout<<"Name:";
        cin>>name;
        cout<<"contact:";
        cin>>contact;
        

            outFile << cnic << " " << name << " " << contact << endl;
        

        outFile.close();
        system("cls");
        cout << "\nowner data saved successfully Now Enter New data.\n";
        goto owner;
        
    }
    

    else if (choice == 2) {
        
        ifstream inFile("owner.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string searchcnic;
        cout << "Enter owner to search: ";
        cin >> searchcnic;

        string cnic,name,contact;
        int found = 0;

        while (inFile >> cnic >> name >> contact ) {
            if (cnic == searchcnic) {
                cout << "\nowner Found:\n";
                cout << "CNIC: " << cnic << endl;
                cout << "Name: " << name << endl;
                cout << "Contact No: " << contact << endl;
               
                found = 1;
                break;
            }
        }

        if (found == 0) {
            cout << "Invalid owner cnic\n";
        }

        inFile.close();
//         system("cls");
        
    }

    else if (choice == 3) {
        // OPTION 3: DISPLAY ALL DATA
        ifstream inFile("owner.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

       string cnic,name,contact;

        cout << "\nAll owner Data:\n";
        cout << "CNIC\tName\tContact NO\n";

        while (inFile >> cnic >> name >> contact ) {
            cout << cnic<<"\t"<<name<<"\t"<<contact<<"\t"<< endl;
        }

        inFile.close();
    }

   
    

	 else {
        cout << "Invalid choice. Please run the program again.\n";
//         system("cls");
        
    }

    return 0;
}
else if(choices==2){
	flat:
    int choice;

    cout << "(----Flat data----)\n";
    cout << "Press 1 to Save  Flat Data\n";
    cout << "Press 2 to Search Flat by Flat No\n";
    cout << "Press 3 to Display Flat data\n";
    
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
    	flat_data:
        // OPTION 1: SAVE STUDENTS TO FILE
        ofstream outFile("flat.txt",ios::app); // append mode

        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return 1;
        }

        string floor,flat,rooms;
        cout<<"Enter floor number:";
        cin>>floor;
        cout<<"Enter flat No:";
        cin>>flat;
        cout<<endl;
        if(check_flat(flat)==true){
        	system("cls");
        	cout<<"Flat Number already exist plz change flat No"<<endl;
        	goto flat_data;
        	return false;
		}
        cout<<"Enter No of Bedrooms:";
        cin>>rooms;
        

            outFile << floor << " " << flat << " " << rooms  << endl;
        

        outFile.close();
         system("cls");
        cout << "\nFlat data saved successfully enter new flat data.\n";
        goto flat;

        
    }
    

    else if (choice == 2) {
       
        ifstream inFile("flat.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string searchflat;
        cout << "Enter Flat Number to search: ";
        cin >> searchflat;

        string floor,flat,rooms;
        int found = 0;

        while (inFile >> floor >> flat >> rooms ) {
            if (flat == searchflat) {
                cout << "\nflat Found:\n";
                cout << "Floor Number: " << floor << endl;
                cout << "Flat No: " << flat << endl;
                cout << "No of Bedrooms: " << rooms << endl;
               
                found = 1;
                break;
            }
        }

        if (found == 0) {
            cout << "Invalid Flat Number\n";
        }

        inFile.close();
//         system("cls");
       
    }

    else if (choice == 3) {
        // OPTION 3: DISPLAY ALL DATA
        ifstream inFile("flat.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string floor,flat,rooms;

        cout << "\nAll flat Data:\n";
        cout << "Floor_No Flat_No Rooms\n";

        while (inFile >> floor >> flat >> rooms ) {
            cout << floor << "\t" << flat << "\t" << rooms  << endl;
        }

        inFile.close();
    }

   
    

	 else {
        cout << "Invalid choice. Please run the program again.\n";

        
    }

    return 0;
}
else if(choices==3){
car:
    int choice;

    cout << "(----Car Data----)\n";
    cout << "Press 1 to Save New car Data\n";
    cout << "Press 2 to Search car by chasis No\n";
    cout << "Press 3 to Display Car Data\n";
    
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
    	car_data:
        // OPTION 1: SAVE STUDENTS TO FILE
        ofstream outFile("car.txt",ios::app); // append mode

        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return 1;
        }

        
        
        for (int i = 0; i < 1; i++) {
            string car,chasis;
            
            

            cout << "Car name: ";
            cin >> car;
           
            	
			
            cout << "Chasis no: ";
            cin >> chasis;
            
            cout<<endl;
            if(check_chasis(chasis)==true){
            	system("clr");
            	cout<<"this chasis number already exist plz use another chasis No";
            	goto car_data;
            	return false;
			}
           
            outFile << car << " " << chasis  << endl;
        }

        outFile.close();
         system("cls");
        cout << "\nCar data saved successfully Enter New Car data.\n";
        goto car;
       
        
    }
    

    else if (choice == 2) {
        // OPTION 2: SEARCH BY ROLL NUMBER
        ifstream inFile("car.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string searchcar;
        cout << "Enter Roll Number to search: ";
        cin >> searchcar;

       string car,chasis;
            
        int found = 0;

        while (inFile >> car >> chasis ) {
            if (chasis == searchcar) {
                cout << "\ncar Found:\n";
                cout << "Car Name: " << car << endl;
                cout << "Chasis No: " << chasis << endl;
                
                found = 1;
                break;
            }
        }

        if (found == 0) {
            cout << "Invalid chasis Number\n";
        }

        inFile.close();
//         system("cls");
        
    }

    else if (choice == 3) {
        // OPTION 3: DISPLAY ALL DATA
        ifstream inFile("car.txt");

        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return 1;
        }

        string car,chasis;

        cout << "\nAll car Data:\n";
        cout << "Car Name\tChasis No\n";

        while (inFile >> car >> chasis ) {
            cout << car << "\t" << chasis  << endl;
        }

        inFile.close();
    }

   
    

	 else {
        cout << "Invalid choice. Please run the program again.\n";
//         system("cls");
       
    }

    return 0;
}
}

	
	

