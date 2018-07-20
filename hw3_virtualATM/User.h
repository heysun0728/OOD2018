#include "Transaction.h"
class User{
	private:
		const char* name;
		int ID;
		Account* account;
		string trans[100];
	public:
		User(const char*);
		~User();
		const string getUsername();
		Account* getAccount();
		int getID();
		bool putTrans();
		void getTrans();
};


