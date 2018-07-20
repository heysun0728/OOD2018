#include "WordLocator.h"

/*
using namespace std;
string cmd;
vector<string> arr;
vector<string> f;
void error(){//print error string
	cout<<"ERROR: Invalid command"<<endl;
}
void load(string filename){
	ifstream file;
	string line;
	file.open(filename);
	if(!file){
		cout<<"ERROR: Error reading from file"<<endl;
	}else{
		while(getline(file,line)){
			//replace some char by space
			for(int i=0;i<line.length();i++){
				char c=line[i];
				if((!isalpha(c))&&(!isdigit(c))&&c!='\''){
					line[i]=' ';
				}
			}
			//split into vector f
			stringstream ss(line);
	                string temp;
                	while(ss>>temp) f.push_back(temp);
		}	
	}
	file.close();
}
void locate(string s,int pos){
	int i;	
	int count=0;
	for(i=0;i<f.size();i++){
		if(s==f[i]) count++;
		if(count==pos){
			cout<<(i+1)<<endl;
			break;
		}
	}	
	if(i==f.size()) cout<<"No matching entry"<<endl;
}
bool is_digits(string str)
{
	for(int i=0;i<str.length();i++){
		if(!isdigit(str[i])) return false;
	}
	return true;
}

int work(){//choose how to work and check paragraph
	if(arr[0]=="load"){
		if(arr.size()!=2) error();
		else load(arr[1]); 
	}	
	else if(arr[0]== "locate"){
		if(arr.size()!=3) error();
		else if(!is_digits(arr[2])) error();
		else{
			int pos=atoi(arr[2].c_str());
			if(pos>0) locate(arr[1],pos);
			else error();
		}
	}
	
	else if(arr[0]=="new"){
		if(arr.size()!=1) error();
		else	f.clear();
	}
	else if(arr[0]=="end"){
		if(arr.size()!=1) error();
		return 1;
	}
	else{		
		error();
	}
	return 0;
}
int main(int argc,char *argv[]){
	cout<<">";
	while(getline(cin,cmd)){
		stringstream ss(cmd);
		string temp;
		arr.clear();
		while(ss>>temp) arr.push_back(temp);
		if(work()) break;		
		cout<<">";
	}
	return 0;
}*/
int main(int argc,char *argv[]){
	WordLocator mywl;
	return 0;
}
