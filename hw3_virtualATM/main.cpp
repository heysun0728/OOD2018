#include "User.h"
int main(){
	//create two user
	cout<<"【 create two user 】"<<endl;	
	User* u1=new User("Jhon");
	User* u2=new User("Mary");
	cout<<endl;

	//show their id and name
	cout<<"【 show their id and name 】"<<endl;
	cout<<"user u1---name:"<<u1->getUsername()<<" id:"<<u1->getID()<<endl;
	cout<<"user u2---name:"<<u2->getUsername()<<" id:"<<u2->getID()<<endl;
	cout<<endl;	

	//carry out a transaction
	Account* a1=u1->getAccount();
	Account* a2=u2->getAccount();
	cout<<"【 u1 deposit $400 (0+400=400) 】"<<endl;
	if(!a1->deposit(400)) cout<<"fial"<<endl;
	cout<<endl;
	cout<<"【 u1 withdraw $500 (400<500 fail) 】"<<endl;
	if(!a1->withdraw(500)) cout<<"you dont have enough money to withdraw"<<endl;
	cout<<endl;
	cout<<"【 now u1 amount: $400 】"<<endl;
	cout<<"your amount is:"<<a1->getAmount()<<endl;
	cout<<endl;
	cout<<"【 u1 withdraw $100 (400-100=300) 】"<<endl;
	if(!a1->withdraw(100)) cout<<"fail"<<endl;
	cout<<endl;	
	cout<<"【 u1 transfer $100 to u2 (id1:0+100=100 id0:300-100=200) 】"<<endl;
	if(!a1->transferMoney((*a2),100)) cout<<"fail"<<endl;
	cout<<endl;	

	//get u1,u2 trans
	cout<<"【 get u1 trans 】"<<endl;
	u1->getTrans();
	cout<<endl;	
	cout<<"【 get u2 trans 】"<<endl;
	u2->getTrans();

	//delete u1,u2
	cout<<"【 delete two users 】"<<endl;
	delete u1;
	delete u2;
	return 0;
}
