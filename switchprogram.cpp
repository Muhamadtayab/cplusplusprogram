
#include <iostream>
using namespace std;
void evenodd(int n) {
    	cout<<"enter number:";
	cin>>n;
	if(n%2==0) {
		cout<<"even";
	} else {
		cout<<"odd";
	}
	
	
}
void factorial(int n) {
    	cout<<"enter number:";
	cin>>n;
	int result,i;
	result=n;
	for(i=n-1; i>1; i--) {
		result=result*i;
	}
	cout<<result;
	
}

void fab(int n) {
    	cout<<"enter number:";
	cin>>n;
	int a=0,b=1,c,i;
	
	for(i=0; i<n; i++) {
		cout<<a;
		c=a+b;
		a=b;
		b=c;

	}
	
}
void prime(int n) {
	int i;
		cout<<"enter number:";
	cin>>n;
	for(i=2; i<n; i++) {
		if(n%i==0) {
			break;
		}
	}
	if(n==i) {
		cout<<"prime";
	}
	else {
		cout<<"not prime";
	}
	
}

int main()
{
	int n,choice;
	cout<<"1 for evenodd"<<endl;
	cout<<"2 for factorial"<<endl;
	cout<<"3 for fabnaci"<<endl;
	cout<<"4 for primeNo"<<endl;
	cout<<"5 for sum of matrix"<<endl;
	
	cout<<"Enter your choice:";
	cin>>choice;

	switch(choice) {
	case 1:
		evenodd(n);
		break;
	case 2:
		factorial(n);
		break;
	case 3:
		fab(n);
		break;
	case 4:
		prime(n);
		break;
	case 5:
		int row;
		int col;
		int n;
		cout<<"enter number of rows:";
		cin>>row;
		cout<<"enter number of colum:";
		cin>>col;
		int array1[row][col];
		int array2[row][col];
		int sum[row][col];
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {

				cout<<"enter a number"<<"["<<i<<"]["<<j<<"]"<<"=";
				cin>>array1[i][j];

			}
		}

		cout<<endl<<"now array 2:"<<endl;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {

				cout<<"enter a number"<<"["<<i<<"]["<<j<<"]"<<"=";
				cin>>array2[i][j];

			}
		}
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				sum[i][j]=array1[i][j]+array2[i][j];
			}

		}


		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				cout<<array1[i][j]<<"\t";

			}
			cout<<endl;
		}
		cout<<endl<<"now display array 2:"<<endl;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				cout<<array2[i][j]<<"\t";

			}
			cout<<endl;
		}
		cout<<"sum of matrix"<<endl;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				cout<<sum[i][j]<<"\t";

			}
			cout<<endl;
		}
break;

}


	return 0;
}

