#include "Transaction.h"
Account::Account(){}
Account::Account(int a,int i){
	ID=i;
	amount=a;
	translen=0;
	cout<<"---Account constructed"<<endl;
}
Account::~Account(){
	cout<<"---Account destructed"<<endl;
}
bool Account::withdraw(int deductAmount){
	if(amount<deductAmount)	 return false;
	amount-=deductAmount;
        Transaction t((this),"withdraw",deductAmount,-1);
	trans[translen++]=t.getTranStr();
	return true;
}
bool Account::deposit(int addAmount){
	amount+=addAmount;
	Transaction t((this),"deposit",addAmount,-1);
	trans[translen++]=t.getTranStr();
	return true;
}
bool Account::transferMoney(Account &AccountOfB,int amountToTransfer){
	if(amount<amountToTransfer) return false;	
	amount-=amountToTransfer;
	AccountOfB.deposit(amountToTransfer);
	Transaction t((this),"transferMoney",amountToTransfer,AccountOfB.getID());
	trans[translen++]=t.getTranStr();
	return true;
}
int Account::getTranslen(){
	//cout<<translen<<endl;
	return translen;
}
string* Account::getTrans(){
	return trans;
}
int Account::getAmount(){
	return amount;
}
int Account::getID(){
	return ID;
}

