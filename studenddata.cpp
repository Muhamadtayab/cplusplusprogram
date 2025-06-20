#include <iostream>
using namespace std;

int main() {
	string students[5][5];

	for (int i = 0; i < 5; i++) {
		cout << "Enter data for student " << i + 1 << ":\n";
		cout << "Roll Number: ";
		cin >> students[i][0];

		cout << "Name: ";
		cin >> students[i][1];

		cout << "Father Name: ";
		cin >> students[i][2];

		cout << "Gender: ";
		cin >> students[i][3];

		cout << "Blood Group: ";
		cin >> students[i][4];

		cout << endl;
	}


	cout << "\nStudent Data:\n";
	cout << "RollNo  Name  F__Name  Gender  Blood\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << students[i][j] << "\t";
		}
		cout << endl;
	}
cout<<endl;
cout<<endl;

	cout<<"Now search with roll number..."<<endl;

	string searchRoll;
	cout << "Enter Roll Number to search: ";
	cin >> searchRoll;

	int i;
	for (i = 0; i < 5; i++) {
		if (students[i][0] == searchRoll) {
			cout << "\nStudent Found:\n";
			cout << "Roll Number: " << students[i][0] << endl;
			cout << "Name: " << students[i][1] << endl;
			cout << "Father Name: " << students[i][2] << endl;
			cout << "Gender: " << students[i][3] << endl;
			cout << "Blood Group: " << students[i][4] << endl;
			break;
		}
	}

	if (i == 5) {
		cout << "Invalid Roll Number\n";
	}

	return 0;
}
