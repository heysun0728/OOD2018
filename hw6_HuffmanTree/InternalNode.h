#ifndef _NODE_H_
#define _NODE_H_
#include "Node.h"
#endif
class InternalNode : public Node {
	private:
		Node* lChild; 
		Node* rChild; 
	public:
		InternalNode();
		InternalNode(int,Node*,Node*);
		~InternalNode();
		int getNodeType(); 
		Node* getLChild();
		Node* getRChild();
		char getValue(); 
};

