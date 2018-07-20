#include "User.h"
static int makeid=0;
User::User(const char* n){
	ID=makeid++;	
	name=n;
	account=new Account(0,ID);
	//account=a; 
	cout<<"---User constructed"<<endl;	
}
User::~User(){
	delete account;
	cout<<"---User destructed"<<endl;		
}
int User::getID(){
	return ID;
}
const string User::getUsername(){
	return name;
}
Account* User::getAccount(){
	return account;
}
void User::getTrans(){
	putTrans();
	for(int i=0;i<100;i++){
		if(trans[i].empty()) break;		
		cout<<trans[i]<<endl;
	}
}
bool User::putTrans(){
	string* t=account->getTrans();
	//cout<<account.getTranslen()<<endl;
	for(int i=0;i<account->getTranslen();i++){
		trans[i]=t[i];
	}	
	return true;
}

