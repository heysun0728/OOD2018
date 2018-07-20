#include "Node.h"
Node::Node(int f){
	freq=f;
}
Node::~Node(){}
int Node::getFreq(){
	return freq;
}


