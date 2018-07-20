#include "TerminalNode.h"
#include <iostream>
using namespace std;
TerminalNode::TerminalNode():Node(0),value('\0'){}
TerminalNode::TerminalNode(int f,char v):Node(f),value(v){}
TerminalNode::~TerminalNode(){}
int TerminalNode::getNodeType(){
	return 0;
}
char TerminalNode::getValue(){
	return value;
}
Node* TerminalNode::getLChild(){
	cout<<"Terminal Node doesnt have Lchild"<<endl;	
	return NULL;
}
Node* TerminalNode::getRChild(){
	cout<<"Terminal Node doesnt have Rchild"<<endl;	
	return NULL;
}
