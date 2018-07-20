#include "HuffmanTree.h"
using namespace std;

HuffmanTree::HuffmanTree(const string& s):nodeNum(0),root(NULL){
	int i;	
	for(i=0;i<95;i++){
		charFreq[i]=0;
	}
	findFrequency(s);
	makeTree();	
	getCharCode(root,"");
}
HuffmanTree::~HuffmanTree(){
	recurDelete(root);
}
void HuffmanTree::recurDelete(Node* n){//delete each node in tree with recursive
	if(n->getNodeType()==1){
		if(n->getLChild()!=NULL) recurDelete(n->getLChild());
		if(n->getRChild()!=NULL) recurDelete(n->getRChild());
	}
	delete n;
}
void HuffmanTree::findFrequency(const string& s){//find each character frequency
	int i;
	//find each char frequency
	for(i=0;i<s.size();i++){
		charFreq[s[i]-' ']++;
	}
	for(i=0;i<95;i++){
		if(charFreq[i]>0){
			//cout<<nodeNum<<" "<<(char)(' '+i)<<" "<<charFreq[i]<<endl;
			charNode[nodeNum]=new TerminalNode(charFreq[i],' '+i);
			pq.push(0-charFreq[i]);
			nodeNum++;
		}
	}
}
int HuffmanTree::findMinIndex(int m){//use frequency to find character index
	int i;	
	for(i=0;i<nodeNum;i++){
		if(charNode[i]!=NULL && charNode[i]->getFreq()==m) return i;
	}
	return -1;
}
string HuffmanTree::decode(const string& s) const{
	int i;	
	string ans;
	Node* start=root;
	for(i=0;i<s.size();i++){
		if(s[i]=='0') start=start->getLChild();
		else start=start->getRChild();
		if(start->getNodeType()==0){
			ans+=start->getValue();
			start=root;		
		}
	}
	if(start!=root){
		cout<<"error: sequence "<<s<<" cannot be decoded";
		ans="";
	}
	return ans;
}
string HuffmanTree::encode(const string& s) const{
	int i;	
	string ans;
	for(i=0;i<s.size();i++){
		if(printCharCode(s[i]).size()==0){
			cout<<"error: character "<<s[i]<<" cannot be encoded";
			ans="";
			break;
		}
		ans+=printCharCode(s[i]);
	}
	return ans;
}
string HuffmanTree::printCharCode(const char c) const{ //input char and return its code
	return charCode[c-' '];
}
void HuffmanTree::getCharCode(Node* n,string s){ //give every char a code and record it
	if(n->getNodeType()==0){
		//cout<<n->getValue()<<" "<<s<<endl;
		charCode[n->getValue()-' ']=s;
	}
	else{
		if(n->getLChild()!=NULL) getCharCode(n->getLChild(),s+"0");
		if(n->getRChild()!=NULL) getCharCode(n->getRChild(),s+"1");
	}
}

void HuffmanTree::makeTree(){
	int min1,min2,push1,index1,index2;
	Node* minAddr1, *minAddr2;	
	while(1){
		//get left node
		min1=0-pq.top();pq.pop();
		index1=findMinIndex(min1);
		//cout<<"index1:"<<index1<<endl;
		minAddr1=charNode[index1];
		charNode[index1]=NULL;
		//get right node
		min2=0-pq.top();pq.pop();
		index2=findMinIndex(min2);
		//cout<<"index2:"<<index2<<endl;
		minAddr2=charNode[index2];
		charNode[index2]=NULL;
		//make new node
		push1=min1+min2;
		if(pq.empty()){
			root=new InternalNode(push1,minAddr2,minAddr1);
			break;
		}else{
			pq.push(0-push1);
			//cout<<nodeNum<<" "<<"in"<<" "<<push1<<endl;
			charNode[nodeNum++]=new InternalNode(push1,minAddr2,minAddr1);
		}
	}
}
