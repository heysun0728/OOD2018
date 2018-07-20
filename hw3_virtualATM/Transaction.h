#include "Account.h"
class Transaction{
	private:
		string type;
		Account* account;
		int amount;
		int transferTo;
	public:
		Transaction();
		Transaction(Account*,const string,const int,int);
		~Transaction();		
		void print();
		string getTranStr();
};
