# Bag

實作template寫出一個Bag的class。

內容如下:
### 1. Bag class
+ constructor:

印出Bag constructed
建立一個空的背包

+ Destructor: 

印出Bag destructed

+ Copy constructor: 

印出Bag copy constructed

當一個全新的背包被創建為現有背包的copy時，必須分配足夠的節點(node)來保存原始列表的copy。

+ Assignment operator: 

印出Bag assignment operator

將等號右側的Bag指派給等號左側的Bag時，

等號左側的Bag應為等號右側Bag的複本，等號左側的Bag舊有的值不該存在

其中包含的函數有: 
<pre>bool empty() const; //如果背包是空的就回傳true，否則回傳false
int size() const; //回傳背包中物品總數
int uniqueSize() const; //回傳背包中相異物品數
bool insert(const ItemType& value); //將一個物品value加入背包中，成功加入便回傳true
int erase(const ItemType& value); //移除背包中一個物品value，回傳移除的是第幾個物品，若背包中沒這樣物品則回傳0
int eraseAll(const ItemType& value); //移除所有物品value，回傳移除的數量
bool contains(const ItemType& value) const; //如果背包中包含物品value就回傳true，否則回傳false
int count(const ItemType& value) const; //回傳物品value在背包中的數量</pre>

+ Iteration functions: 

走訪背包中物品所需用到的函式

雖然投影片上是寫初始化時用手指指到隨意一個物品，走訪時可以用任意順序走訪，next()要指到相異的物品，

但為了批改方便，大家答案一致，走訪順序就是insert()順序，next()就一路依放入順序指下去，不管是否相異物

<pre>void start();</pre>
初始化手指，將手指指到第一個物品

若包包為空，印Please input item，並且程式不能壞掉

<pre>void next();</pre>
將手指指到下一個物品

若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫next()

若還未將手指初始化就呼叫next()，印Please initializes，並且程式不能壞掉

若已經走訪完畢，讓手指不再指向任何物品

<pre>bool ended() const;</pre>
如果手指沒有指向任何物品就回傳true，否則回傳false

<pre>const ItemType& currentValue() const;</pre>
回傳手指指到的物品

若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentValue()

若還未將手指初始化就呼叫currentValue()，印Please initializes，並且程式不能壞掉

<pre>int currentCount() const;</pre>
回傳手指指到的是第幾個物品

若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentCount()

若還未將手指初始化就呼叫currentCount，印Please initializes，回傳0，並且程式不能壞掉

! 注意: Bag中的物品必須用circular doubly-linked list 來連接 
doubly-linked list 包含一個標示「開頭」用的 dummy element，如下圖所示
![](https://github.com/heysun0728/Bag/blob/master/list.png "doubly-linked list")

! 撰寫 destructor 時請注意把所有的元素刪乾淨，避免 memory leak。 

### 2. non-member functions
<pre>void combine(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result);</pre>
result中有bag1和bag2中的所有東西，bag1和bag2原有的物品不能有任何改變

在這裡就不規定result順序，只要result內物品數量都正確即可

<pre>void subtract(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result);</pre>
假設bag1中有n1個"duck", bag2中有n2個"duck",如果n1>n2, 

則result中有n1-n2個"duck"，如果n1<=n2,則result沒有"duck"

不規定result順序，只要result內物品數量都正確即可

### 3. MakeFile
並且當使用者輸入 make 時，可以從你的 source code 編譯出執行檔。

