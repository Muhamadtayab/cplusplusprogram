#include <iostream>
#include <fstream>
using namespace std;
class person{
	public:
	string name;
	string gender;
	string cast;
	string cnic;
	
	void setName(string n){
		name=n;
	}
	void setGender(string g){
		gender=g;
	}
	void setCast(string c){
		cast=c;
	}
	void setCnic(string cn){
		cnic=cn;
	}
	string getName(){
		return name;
	}
	string getGender(){
		return gender;
	}
	string getCast(){
		return cast;
	}
	string getCnic(){
		return cnic;
	}
	
	
};
class Student: public person{
	public:
	string department;
	string semester;
	double GPA;
	void setDepartment(string d){
	department=d;
	}
	void setSemester(string sem){
		semester=sem;
	}
	void setGpa(double gpa){
		GPA=gpa;
	}
	string getDepartment(){
		return department;
	}
	string getSemester(){
		return semester;
	}
	double getGpa(){
		return GPA;
	}
	
};
class Teacher: public person{
	public:
	string Grade;
	string Subject;
	void setGrade(string grade){
		Grade=grade;
	}
	void setSubject(string subject){
		Subject=subject;
	}
	string getGrade(){
		return Grade;
	}
	string getSubject(){
		return Subject; 
	}
};

void addStudent(Student obj){

	
	ofstream outfile("student.txt",ios::app);
	outfile<<obj.getName()<<" "<<obj.getGender()<<" "<<obj.getCast()
	<<" "<<obj.getCnic()<<" "<<obj.getDepartment()<<" "<<obj.getSemester()
	<<" "<<obj.getGpa()<<endl;
	outfile.close();
	
	
}
void display(){
    string Name, Gender, Cast, Cnic, Department, Semester;
    double Gpa;
    bool found = false;

    ifstream infile("student.txt");
    while(infile >> Name >> Gender >> Cast >> Cnic >> Department >> Semester >> Gpa){
        found = true;
        cout<<"Name:"<<Name<<endl;
        cout<<"Gender:"<<Gender<<endl;
        cout<<"Cast:"<<Cast<<endl;
        cout<<"CNIC:"<<Cnic<<endl;
        cout<<"Department:"<<Department<<endl;
        cout<<"Semester:"<<Semester<<endl;
        cout<<"GPA:"<<Gpa<<endl;
        cout<<"___________"<<endl;
     
    }
    infile.close();

    if(!found){
        cout << "No student data found (file is empty)." << endl;
    }
}

void addTeacher(Teacher obj){

	
	ofstream outfile("teacher.txt",ios::app);
	outfile<<obj.getName()<<" "<<obj.getGender()<<" "<<obj.getCast()<<" "<<obj.getCnic()
	<<" "<<obj.getGrade()<<" "<<obj.getSubject()<<endl;
	outfile.close();
}
void displayTeacher(){
    string Name, Gender, Cast, Cnic, Grade, subject;
    bool found = false;

    ifstream infile("teacher.txt");
    while(infile >> Name >> Gender >> Cast >> Cnic >> Grade >> subject){
        found = true;
        cout<<"Name:"<<Name<<endl;
        cout<<"Gender:"<<Gender<<endl;
        cout<<"Cast:"<<Cast<<endl;
        cout<<"CNIC:"<<Cnic<<endl;
        cout<<"Grade:"<<Grade<<endl;
        cout<<"Subject:"<<subject<<endl;
        cout<<"____________"<<endl;
    }
    infile.close();

    if(!found){
        cout << "No teacher data found (file is empty)." << endl;
    }
}


void updateStudent(string cnic){
    string Name, Gender, Cast, Cnic, Department, Semester;
    double Gpa;
    int found = 0;
    ifstream infile("student.txt");
    ofstream outfile("temp.txt");
    while(infile >> Name >> Gender >> Cast >> Cnic >> Department >> Semester >> Gpa){
        if(Cnic == cnic){
            cout << "---Enter updated info---"<<endl;

           

            cout << "Enter new name: ";
            getline(cin, Name);
            cout << "Enter gender: ";
            getline(cin, Gender);
            cout << "Enter cast: ";
            getline(cin, Cast);
            cout << "Enter CNIC: ";
            getline(cin, Cnic);
            cout << "Enter department: ";
            getline(cin, Department);
            cout << "Enter semester: ";
            getline(cin, Semester);
            cout << "Enter GPA: ";
            cin >> Gpa;
            cin.ignore(); 

            found = 1;
        }
        outfile << Name << " " << Gender << " " << Cast << " " << Cnic << " " << Department << " " << Semester << " " << Gpa << endl;
    }
    infile.close();
    outfile.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if(found == 1)
        cout << "Data updated successfully.\n";
    else 
        cout << "Data not found.\n";
    }


void delStudent(string cnic){
	string Name,Gender,Cast,Cnic,Department,Semester;
	double Gpa;
	int found =0;
	ifstream infile("student.txt");
	ofstream outfile("temp.txt");
	while(infile>>Name>>Gender>>Cast>>Cnic>>Department>>Semester>>Gpa){
		if(Cnic==cnic){
			
		
			found = 1;
			continue;
					}
					outfile<<Name<<" "<<Gender<<" "<<Cast<<" "<<Cnic<<" "<<Department<<" "<<Semester<<" "<<Gpa;
	}
	infile.close();
	outfile.close();
	
	remove("student.txt");
	rename("temp.txt","student.txt");
	
	if(found==1)
		cout<<"delete student data";
	else
		cout<<"data not found";
	
}

void updateTeacher(string cnic){
    string Name, Gender, Cast, Cnic, Grade, subject;
    
    int found = 0;
    ifstream infile("teacher.txt");
    ofstream outfile("temp.txt");
    while(infile >> Name >> Gender >> Cast >> Cnic >> Grade>>subject){
        if(Cnic == cnic){
            cout << "---Enter updated info---"<<endl;

           

            cout << "Enter new name: ";
            getline(cin, Name);
            cout << "Enter gender: ";
            getline(cin, Gender);
            cout << "Enter cast: ";
            getline(cin, Cast);
            cout << "Enter CNIC: ";
            getline(cin, Cnic);
            cout << "Enter Grade: ";
            getline(cin, Grade);
            cout << "Enter subject: ";
            getline(cin, subject);
            

            found = 1;
        }
        outfile << Name << " " << Gender << " " << Cast << " " << Cnic << " " << Grade << " " << subject <<endl;
    }
    infile.close();
    outfile.close();

    remove("teacher.txt");
    rename("temp.txt", "teacher.txt");

    if(found == 1){
        cout << "Data updated successfully";
    } else {
        cout << "Data not found.";
    }
}


void delTeacher(string cnic){
	string Name,Gender,Cast,Cnic,Grade,subject;
	
	int found=0;
	ifstream infile("teacher.txt");
	ofstream outfile("temp.txt");
	while(infile>>Name>>Gender>>Cast>>Cnic>>Grade>>subject){
		if(Cnic==cnic){
			
		
			found=1;
			continue;
			
					}
					outfile<<" "<<Name<<" "<<Gender<<" "<<Cast<<" "<<Cnic<<" "<<Grade<<" "
					<<subject;
	}
	infile.close();
	outfile.close();
	
	remove("teacher.txt");
	rename("temp.txt","teacher.txt");
	
	if(found==1){
		cout<<"data delete succesfully";
	}else{
		cout<<"data not found";
	}
}


int main(){
	string n,g,c,cn,d,sem,sub,gr;
	double gp;
	int choices;
	cout<<"press 1 for student data"<<endl;
	cout<<"pess 2 for teacher data"<<endl;
	cout<<endl;
	cout<<"enter your choice:";
	cin>>choices;
	if(choices==1){
		int choice;
		cout<<"--select what you need--"<<endl;
	cout<<"press 1 for save data"<<endl;
	cout<<"press 2 for display data"<<endl;
	cout<<"press 3 for update data "<<endl;
	cout<<"press 4 for delete data"<<endl;
	cout<<endl;
	cout<<"enter your choice:";
	cin>>choice;
	if(choice==1){
		
	Student s1;
	cout<<"--Student information--"<<endl;
	
	cout<<endl;
	cin.ignore();
	cout<<"Enter name:";
	getline(cin,n);
	s1.setName(n);
	cout<<"Gender:";
	getline(cin ,g);
	s1.setGender(g);
	cout<<"Enter your Cast:";
	getline(cin ,c);
	s1.setCast(c);
	cout<<"Enter CNIC:";
	getline(cin ,cn);
	s1.setCnic(cn);
	cout<<"Enter department:";
	getline(cin ,d);
	s1.setDepartment(d);
	cout<<"your semester:";
	getline(cin ,sem);
	s1.setSemester(sem);
	cout<<"Gpa:";
	cin>>gp;
	cin.ignore();
	s1.setGpa(gp);
	
	addStudent(s1);
	cout<<endl;
		cout<<"--Data Add succesfully--";
	}
	else if(choice==2){
		
			cout<<"--display student info--"<<endl;
	cout<<endl;
	
display();

	cout<<endl;
	}
	else if(choice==3){
		string searchcnic;
		cout<<"enter cnic to update:";
		cin.ignore();
		getline(cin ,searchcnic);
		updateStudent(searchcnic);
	}
	else if(choice==4){
		string searchcnic;
		cout<<"enter cnic to delete:";
		cin.ignore();
		getline(cin ,searchcnic);
		delStudent(searchcnic);
		
	}
	
		
	}
	else if(choices==2){
		int choice;
		cout<<"press 1 for save Teacher data"<<endl;
		cout<<"press 2 for display teacher data"<<endl;
		cout<<"press 3 for update teacher data"<<endl;
		cout<<"press 4 for delete teacher data"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		if(choice==1){
			Teacher t1;
				cout<<"--Teacher information--"<<endl;
	cout<<endl;
	cin.ignore();
	cout<<"Enter name:";
	getline(cin,n);
	t1.setName(n);
	cout<<"Gender:";
	getline(cin ,g);
	t1.setGender(g);
	cout<<"Enter your Cast:";
	getline(cin ,c);
	t1.setCast(c);
	cout<<"Enter CNIC:";
	getline(cin ,cn);
	t1.setCnic(cn);
	cout<<"Enter Grade:";
	getline(cin ,gr);
	t1.setGrade(gr);
	cout<<"enter subjects:";
	getline(cin ,sub);
	t1.setSubject(sub);
addTeacher(t1);
cout<<"--Data Add succesfully--";

cout<<endl;
		}
		else if(choice==2){
				cout<<"--display Teacher info--"<<endl;
	
	cout<<endl;
	
	displayTeacher();
			
		}
		else if(choice==3){
			string searchcnic;
		cout<<"enter cnic to update:";
		cin.ignore();
		getline(cin ,searchcnic);
		updateTeacher(searchcnic);
			
		}
		else if(choice==4){
			string searchcnic;
		cout<<"enter cnic to delete:";
		cin.ignore();
		getline(cin ,searchcnic);
		delTeacher(searchcnic);
		}
	}
	}
	
	
	
	
	
	
	
	

	


	

