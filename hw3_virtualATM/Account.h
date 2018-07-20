#include <bits/stdc++.h>
using namespace std;
class Account{
	private:
		int ID;
		int amount;
		int translen;
		string trans[100];
	public:
		Account();
		Account(int,int);
		~Account();
		bool withdraw(int);
		bool deposit(int);
		bool transferMoney(Account &,int);
		int getAmount();
		int getID();
		int getTranslen();
		void maketrans(string);
		string * getTrans();
};
