#include <iostream>
#include <string>
using namespace std;

int main(int argc,char *argv[]){
        string s(argv[1]);
        int head=0;
        int tail=s.size()-1;

        while(head<tail){ 
        	while(!isalpha(s[head])&&head<tail) head++;
		while(!isalpha(s[tail])&&head<tail) tail--;
		if(tolower(s[head])!=tolower(s[tail])) break;
        	head++;tail--;
	}
        if(head>=tail) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
	return 0;
}


