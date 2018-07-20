#ifndef _NODE_H_
#define _NODE_H_
#include "Node.h"
#endif
class TerminalNode : public Node{
	private:
		char value;
	public:
		TerminalNode();
		TerminalNode(int,char);
		~TerminalNode();
		int getNodeType();
		Node* getLChild();
		Node* getRChild();
		char getValue();
};
