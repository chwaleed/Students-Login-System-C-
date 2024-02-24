#include <iostream>
#include <fstream>
using namespace std;


class temp{
	string userName, email, password;
	string searchName,searchEmail,searchPassword;
	fstream file;
	public:
		void login();
		void signUp();
		void forget();
}obj;

int main(){
	char choice;
	cout<<"1- Login"<<endl;
	cout<<"2- SignUp"<<endl;
	cout<<"3- Forget Password"<<endl;
	cout<<"4- Exit"<<endl;
	cout<<"5- Enter your choice :: ";
	cin>>choice;
	cin.ignore();
	
	switch(choice){
		case '1':
			obj.login();
			break;
		case '2':
			obj.signUp();
			break;
		case '3':
			obj.forget();
			break;
		case '4':
			return 0;
			break;
		default:
			cout<<"\nInvalid Choice! ";
	}
}

void temp::signUp(){
	cout<<"<----- SignUp ------>"<<endl;
	cout<<"Enter your username :: ";
	getline(cin,userName);
	cout<<"\nEnter your email :: ";
	getline(cin,email);
	cout<<"\nEnter your password :: ";
	getline(cin,password);
	
	file.open("userData.txt", ios :: out | ios :: app);
	file<<userName<<"*"<<email<<"*"<<password<<endl;
	file.close();
}


void temp::login(){
	cout<<"\n<------- Login --------->"<<endl;
	cout<<"Enter your username :: ";
	getline(cin,searchName);
	cout<<"\nEnter your password :: ";
	getline(cin,searchPassword);
	
	file.open("userData.txt",ios :: in);
	getline(file,userName,'*');
	getline(file,email,'*');
	getline(file,password,'\n');
	
	bool isLogin = false;
	while(!file.eof()){
		if (userName == searchName && password == searchPassword){
			cout<<"\nWelcome to the portal."<<endl;
			cout<<"Your username is :: "<<userName<<endl;
			cout<<"Your email is :: "<<email<<endl;
			isLogin = true;
			break;
		}
		getline(file,userName,'*');
		getline(file,email,'*');
		getline(file,password,'\n');
	}
	if(!isLogin){
		cout<<"\nPlease enter valid username or password!"<<endl;
		cout<<"Or try to foget the password.";
	}
	file.close();
}
void temp::forget(){
	cout<<"\n<-------- Forget Password -------------->"<<endl;
	cout<<"Enter your username :: ";
	getline(cin, searchName);
	cout<<"\nEnter your email address :: ";
	getline(cin,searchEmail);
	
	file.open("userData.txt",ios :: in);
	getline(file,userName,'*');
	getline(file,email,'*');
	getline(file,password,'\n');
	
	bool isForget = false;
	while(!file.eof()){
		if(userName == searchName && email == searchEmail){
			cout<<"\nYour Password is :: "<<password<<endl;
			isForget = true;
			break;
		}
		getline(file,userName,'*');
		getline(file,email,'*');
		getline(file,password,'\n');
	}
	if(!isForget){
		cout<<"\nPlease Enter a Valid username and email!";
	}
}









































