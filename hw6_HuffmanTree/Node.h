class Node{
	protected:
		int freq;
	public:
		Node();
		Node(int);
		virtual ~Node();
		int getFreq();
		virtual int getNodeType()=0;
		virtual char getValue()=0;
		virtual Node* getLChild()=0;
		virtual Node* getRChild()=0;
};
