#include <iostream>
#include <string>
#include "HuffmanTree.h"

using namespace std;

int main(){
	// case 1
	cout<<"***Case 1***"<<endl;
	// Build a Huffman Tree according to the string
	HuffmanTree t1("Abcdaaaabbbbaaaacceee!@&$()#@%*");
	
	// encode a string
	cout << t1.encode("Abcdaaaabbbbaaaacc") << endl;
	
    	// The Hoffman Tree t will be unable to encode this
	// Therefore, please print out error message and return an empty string("") when encounter this.
	cout << t1.encode("Abcdaaaeeeabbbbaaaac@@@%%cRRRRR") << endl;
	
	// decode a string
	cout << t1.decode("101011110000111100101111111010111") << endl;
	
	// The Hoffman Tree t will be unable to decode this
	// Therefore, please print out error message and return an empty string("") when encounter this.
	cout << t1.decode("00101000111001001010101000000000000010101010111111") <<endl;
	cout << t1.decode("1010111100001111001011111110101111") << endl;
	
	//case 2
	cout<<endl;
	cout<<"***Case2***"<<endl;
	HuffmanTree t2("abbcccdddd");
	cout << t2.encode("aaaabbbbaaaacc") << endl;
	cout << t2.encode("Abcdaaaeeeabbbbaaaac@@@%%cRRRRR") << endl;
	cout<<t2.decode("001001000001011")<<endl;//aabacd
	cout<<t2.decode("0000")<<endl;	

	//case 3 : from tree pic of hw6
	cout<<endl;
	cout<<"***Case 3***"<<endl;
	HuffmanTree t3("bbbbbbbbbbbccccccccddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");	
	cout <<"b:"<<t3.encode("b") << endl;
	cout <<"c:"<<t3.encode("c") << endl;
	cout <<"d:"<<t3.encode("d") << endl;
	cout <<"e:"<<t3.encode("e") << endl;
	cout << t3.decode("1001010")<<endl;//bce
	cout << t3.decode("100101001")<<endl;//error

	//test InternalNode func(which not use in HuffmanTree)
	cout<<endl;
	InternalNode inode;
	inode.getValue();//internal node doesnt have value

	//test TerminalNode func(which not use in HuffmanTree)
	TerminalNode tnode;
	tnode.getLChild();//terminal node doesnt have LChild
	tnode.getRChild();//terminal node doesnt have RChild



	return 0;
}
