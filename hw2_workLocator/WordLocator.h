#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class WordLocator{
	private:
		string cmd;
		vector<string> f;
		vector<string> arr;
	public:
		WordLocator();//constructor
		void error();//print error string
		void load(string);//load file
		void locate(string,int);//locate nth string
		bool is_digits(string);//string is digit or not
		int work();//choose how to work and check paragraph
};
