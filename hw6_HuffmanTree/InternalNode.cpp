#include "InternalNode.h"
#include <bits/stdc++.h>
using namespace std;
InternalNode::InternalNode():Node(0),lChild(NULL),rChild(NULL){}
InternalNode::InternalNode(int f,Node* l,Node* r):Node(f),lChild(l),rChild(r){}
InternalNode::~InternalNode(){}
int InternalNode::getNodeType(){
	return 1;
}
char InternalNode::getValue(){
	cout<<"internal node doesnt have value."<<endl;
	return 0;
}
Node* InternalNode::getLChild(){
	return lChild;
}
Node* InternalNode::getRChild(){
	return rChild;
}

