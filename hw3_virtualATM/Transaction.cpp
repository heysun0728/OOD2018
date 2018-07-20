#include "Transaction.h"
Transaction::Transaction(){}
Transaction::Transaction(Account* a,const string t,const int m,int trID){
	account=a;
	type=t;
	transferTo=trID;
	amount=m;
	cout<<"---Transaction constructed"<<endl;
	print();
}
Transaction::~Transaction(){
	cout<<"---Transaction destructed"<<endl;
}
string Transaction::getTranStr(){
	stringstream ss;
	ss<<"id:"<<account->getID()<<"|Type:"<<type<<" $"<<amount;
	if(transferTo>=0) ss<<" to Account "<<transferTo;
	ss<<"|Balance:"<<account->getAmount()<<endl;
	string s=ss.str();
	return s;
}
void Transaction::print(){
	cout<<getTranStr();
}


