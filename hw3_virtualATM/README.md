# virtual_atm

實作出三個class，分別命名為 Account, User, Transaction，以及主程式和 makefile。

內容如下:

### 1. Account class 
內含ID, amount, deductAmount, amountToTransfer，型態皆為int。 (Account 之間的 ID 不可重複)

AccountOfB：記錄交易對象

constructor:
<pre>Account(int amount, int ID) (amount 為帳戶初始金額)</pre>


其中包含的函數有:
<pre>1. bool withdraw()：提取一定金額，成功回傳true，否則回傳false
2. bool deposit()：存入一定金額，成功回傳true
3. bool transferMoney(Account &AccountOfB, int amountToTransfer)：把一定金額(amountToTransfer) 轉到另一個帳戶(AccountOfB)
4. int getAmount()：查詢目前帳戶金額
</pre>

### 2. User class (20%)
內含name, ID, account, trans[]。其中name為一個字串

<pre>ID : 型態為int，User 之間的 ID 不可以重複。
account : 上述的 account class
trans[] : 紀錄交易資訊，陣列大小可以自訂。</pre>

constructor:

<pre>User(const char &name[])</pre>

其中包含的函數為:
<pre>1. char *getUsername()： 回傳username
2. Account &getAccount()：回傳user Account
3. int getID()：回傳 user ID</pre>

### 3. Transaction class
內含type, account, amount 三個變數。其中type為一個字串，紀錄交易的類型
amount 為 int，紀錄交易金額。
account 為一個 reference，指向執行交易的 account。

constructor:
<pre>Transaction(Account &account, char type[])</pre>

其中包含的函數為:
<pre>void print()：印出交易詳細資料 </pre>


### 4. 主程式
你可以直接利用投影片上的範例，並補上缺少的部分，或是自己寫一個也可以。
你的主程式要執行
1. 存款、提款
2. 轉帳交易，並記錄交易明細(交易的類型、帳戶、金額)
3. 明細查詢 (應列出使用者帳號的交易明細) 

### 5. MakeFile
並且當使用者輸入 make 時，可以從你的 source code 編譯出執行檔。

[注意事項]
1. 每一個class應該放在單獨的檔案中。
如果你的程式有 ball.cube兩個class的話
你的source code應該要有:
makefile, main.cpp, cube.h, cube.cpp, ball.h, ball.cpp

2. 每次執行constructor destructor時，
印出xx constructed, xx destructed (xx為class名稱)

3. 所有的member variable都應該設為private,
並讓主程式用public member function去存取或改變member variable。

### 6.檔案輸出
<pre>【 create two user 】
---Account constructed
---User constructed
---Account constructed
---User constructed

【 show their id and name 】
user u1---name:Jhon id:0
user u2---name:Mary id:1

【 u1 deposit $400 (0+400=400) 】
---Transaction constructed
id:0|Type:deposit $400|Balance:400
---Transaction destructed

【 u1 withdraw $500 (400<500 fail) 】
you dont have enough money to withdraw

【 now u1 amount: $400 】
your amount is:400

【 u1 withdraw $100 (400-100=300) 】
---Transaction constructed
id:0|Type:withdraw $100|Balance:300
---Transaction destructed

【 u1 transfer $100 to u2 (id1:0+100=100 id0:300-100=200) 】
---Transaction constructed
id:1|Type:deposit $100|Balance:100
---Transaction destructed
---Transaction constructed
id:0|Type:transferMoney $100 to Account 1|Balance:200
---Transaction destructed

【 get u1 trans 】
id:0|Type:deposit $400|Balance:400

id:0|Type:withdraw $100|Balance:300

id:0|Type:transferMoney $100 to Account 1|Balance:200


【 get u2 trans 】
id:1|Type:deposit $100|Balance:100

【 delete two users 】
---Account destructed
---User destructed
---Account destructed
---User destructed
</pre>
　
