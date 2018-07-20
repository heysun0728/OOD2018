# HuffmanTree
實作一個稱為HuffmanTree的class，這個class可以由一個字串生成一個Huffman編碼樹。

圖中為一個利用「含有11個b, 8個c, 12個d, 49個e」的字串建立的 Huffman Tree，

其建立步驟如下:
(1) b,c,d,e 稱為 terminal node，頻率分別是 11,8,12,49
(2) 取頻率最小的 2 個 terminal node 生成一個樹，並且把頻率較高的那一個放在左邊，
(假設兩個節點頻率相同，則不管方向，不論放左邊或右邊都可以)
新生成的節點(p)稱為 internal node，其頻率等於所有的子節點(child node)的頻率的總和。
(3) 再取所有的 node 中頻率最低的 2 個 node (不論是 terminal 還是 internal node) 生成一個樹。
(4) 不斷重複，直到所有的 terminal node 都被加進 Huffman Tree 裡面。
此時這個 Huffman Tree 的結構就可以用來對字串編碼，例如 ，b 會變成 100。

![](./huffman1.png)
![](./huffman2.png)
![](./huffman3.png)
![](./huffman4.png)



2. 使用 Node, InternalNode, TerminalNode 三個 class 來儲存樹的節點。
其中 InternalNode 和 TerminalNode 都繼承 Node。

* Node 包含以下內容:
```
protected:
    int freq; // 儲存 terminal node 的字頻，或 internal node 所有子節點的字頻總和。
public:
    int getFreq()
    virtual int getNodeType() // 0: terminal node 1: internal node
    virtual char getValue()
    virtual Node* getLChild()
    virtual Node* getRChild()
```
* InternalNode 包含以下內容:
```
private:
    Node* lChild // left child
    Node* rChild // right child
public:
    int getNodeType() // 0: terminal node 1: internal node
    Node* getLChild()
    Node* getRChild()
    char getValue() // internal node 沒有 value，因此請印出提示訊息，並且 return 0。
```
* TerminalNode 包含以下內容:
```
private:
    char value // 儲存這個 node 代表的字元
public:
    int getNodeType() // 0: terminal node 1: internal node
    Node* getLChild() // terminal node 沒有 LChild，因此請印出提示訊息，並且 return NULL。
    Node* getRChild() // terminal node 沒有 RChild。
    char getValue()
```

* class HuffmanTree 包含以下的內容:
```
private:
    Node* root
    HuffmanTree(const string& s)
    /*可以接受一個字串(string)，計算這個字串的各個字元(char)的頻率(即同一個字元的總數)，
    生成對應的 Huffman 編碼樹。
    輸入字串包含 ASCII 表上 32(空白) 到 126(~) 為止的所有符號，
    包含英文字母(有區分大小寫)、空白及逗號、括號等符號。*/

    ~HuffmanTree()
    string encode(const string& s) const //把一個字串編碼成 001010101100... ，並以 string 的形式輸出。
    //當出現無法編碼的字元時，印出提示訊息，並回傳空字串。

    string decode(const string& s) const //把經由 Huffman Tree 編碼成 001010101100... 的訊息解碼成原本的字串。
    //無法成功解碼時，印出提示訊息，並回傳空字串。
```