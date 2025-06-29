#include <iostream>
using namespace std;
class students{

string name;
string father_name;
int age;

	public:

void setname(string n){
	name=n;
}
void setfather_name(string f_n){
	father_name=f_n;
}
void setage(int a){
	age=a;
}
string getname(){
	return name;
}
string getfather_name(){
	return father_name;
}
int getage(){
	return age;
}

};
int main(){
	string n,f_n;
	int a;
	students s1;
	cout<<"Enter Name:";
getline(cin, n);
	s1.setname(n);
	cout<<"Enter father name:";
	getline(cin, f_n);
	s1.setfather_name(f_n);
	cout<<"Enter Age:";
	cin>>a;
	s1.setage(a);
	
	cout<<endl;
	
	cout<<"----display student info----"<<endl;
	cout<<"Name:"<<s1.getname()<<endl;
	cout<<"Father Name:"<<s1.getfather_name()<<endl;
	cout<<"Age:"<<s1.getage()<<endl;
	
	return 0;
}
