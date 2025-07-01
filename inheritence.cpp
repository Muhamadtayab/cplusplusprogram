#include <iostream>
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

int main(){
	string n,g,c,cn,d,sem,sub,gr;
	double gp;
	Student s1;
	Teacher t1;
	cout<<"--Student information--"<<endl;
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
	s1.setGpa(gp);
	cout<<endl;
	
	cout<<"--display student info--"<<endl;
	
	cout<<"Name:"<<s1.getName()<<endl;
	cout<<"Gender:"<<s1.getGender()<<endl;
	cout<<"Cast:"<<s1.getCast()<<endl;
	cout<<"CNIC:"<<s1.getCnic()<<endl;
	cout<<"department:"<<s1.getDepartment()<<endl;
	cout<<"semester:"<<s1.getSemester()<<endl;
	cout<<"GPA:"<<s1.getGpa()<<endl;
	
	cout<<endl;
	
	cout<<"--Teacher information--"<<endl;
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
	
	cout<<"--display Teacher info--"<<endl;
	
	cout<<"Name:"<<t1.getName()<<endl;
	cout<<"Gender:"<<t1.getGender()<<endl;
	cout<<"Cast:"<<t1.getCast()<<endl;
	cout<<"CNIC:"<<t1.getCnic()<<endl;
	cout<<"Grade:"<<t1.getGrade()<<endl;
	cout<<"subject:"<<t1.getSubject()<<endl;

	
	
}
