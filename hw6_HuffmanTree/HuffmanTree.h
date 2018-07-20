#include "InternalNode.h"
#include "TerminalNode.h"
#include <bits/stdc++.h>
using namespace std;
class HuffmanTree{
	public:
		HuffmanTree(const string&);
		~HuffmanTree();
		string encode(const string&) const;
		string decode(const string&) const;
	private:
		Node* root;
		Node* charNode[300];
		string charCode[95];
		int charFreq[95];
		int nodeNum;
		priority_queue<int> pq;
		void makeTree();
		void recurDelete(Node*);
		void getCharCode(Node*,string);
		void findFrequency(const string&);
		int findMinIndex(int);
		string printCharCode(const char)const;

};
