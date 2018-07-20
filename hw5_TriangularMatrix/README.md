# MatrixManipulation
實作一個稱為 Matrix 的 class，並利用 operator overloading 進行矩陣的各種運算。

1. 實作一個稱為 Matrix 的 class，用來儲存上三角/下三角矩陣的資訊，
並利用 operator overloading 進行矩陣的各種運算。
矩陣的 element(元素) 為 double，矩陣資訊可以用任何方式儲存，但必須符合以下 4 個條件: 

* 這個 class 必須要能夠儲存不同大小的矩陣 (由於這次儲存的都是上三角/下三角矩陣，矩陣的列數都和行數相等)

* 這個 class 可以儲存一個上三角矩陣，也可以儲存一個下三角矩陣。

* 只能存上三角/下三角矩陣所需的元素(element)個數，不能有多餘的 element。(例如 2x2 的下三角矩陣只能存 3 個，3x3 的下三角矩陣只能存 6 個 element，依此類推。)

* 所有的 member variable 都應該是 private，主程式只能透過 public 的 function 或 operator 來存取物件的內容。
　
 
2. class 的內容要和主程式放在不同的檔案，並附上 TriangularMatrix.h ，

讓主程式可以利用 #include "TriangularMatrix.h" 來使用這個 class。
　
 
3. class 中必須包含constructor、destructor，以及一個 copy constructor，

用來把另一個 Matrix 的內容複製過來。
```
Matrix (int n=2);
Matrix (const Matrix& m); // copy constructor
~Matrix(); // destructor

destructor 必須能夠確保物件中所有的東西都有「刪乾淨」，不能造成 memory leak。
```
4. member function 包含:

void readMatrix(): 

提示使用者輸入矩陣的大小，矩陣是上三角或下三角矩陣，以及矩陣包含的元素(element)。

其中元素(element)的部分只需要輸入右上(上三角)或左下(下三角)的部分即可。
```
例如要建立以下的下三角矩陣的話，
4　　0　　0
3　　2.5　0
1　　2　　2
流程大致是:
<prompt> specify number of rows:
<user input> 3
<prompt> is upper or lower triangular: (upper: 1, lower:0)
<user input> 0
<prompt> input elements of the matrix:
<user input> 4 3 2.5 1 2 2
```
int size() const: 傳回矩陣的行數(=列數) 


5. operator overloading 包含:

=: copy assignment, 把 const Matrix& m 的內容套用到目前物件中。

const Matrix& operator=(const Matrix& m)

<<:讓使用者可以用 cout << x 印出矩陣的內容 

friend ostream& operator<<(ostream& out, const Matrix& x)

印出的形式如下:

4　　0　　0

3　　2.5　0

1　　2　　2

矩陣的各個元素(element)不一定要對齊，但至少要能清楚看出第幾行第幾列是什麼。


(): 回傳矩陣的第 i 列(row)，第 j 行(column)的值

double operator()(int i, int j) const

以下面這個矩陣來說， M(2,1) 應該回傳 3 ，M(1,3)應該回傳 0。
4　　0　　0

3　　2.5　0

1　　2　　2


[矩陣] + - * [矩陣]:矩陣的相加、相減、相乘 

矩陣大小必須相同才能相加、相減、相乘，

此外上三角矩陣和下三角矩陣不可相加、相減、相乘

當矩陣之間無法相加、減、乘時，

必須印出提示 (例如: You cannot multiply an upper triangular matrix with a lower triangular matrix)，

例如: M1 為一個 2x2 矩陣， M2 為 3x3 矩陣，

當執行 M3 = M1 x M2 時，程式必須印出提示，而且 M1, M2 的內容不可以動到，但 M3 變成了什麼，則不在考慮範圍內。

(兩種作法擇一即可)

作法一:
```
Matrix operator+(const Matrix& rt);
Matrix operator-(const Matrix& rt);
Matrix operator*(const Matrix& rt);
```

作法二:
```
friend Matrix operator+(const Matrix& lt, const Matrix& rt);
friend Matrix operator-(const Matrix& lt, const Matrix& rt);
friend Matrix operator*(const Matrix& lt, const Matrix& rt);
```


[矩陣] * [常數]:矩陣和常數相乘，即把[矩陣]的每一個元素(element)都和[常數]相乘 
```
作法一:
Matrix operator*(double s);
作法二:
friend Matrix operator*(const Matrix& lt, double s);
```
[常數] * [矩陣]: [3%]
```
friend Matrix operator*(double s, const Matrix& rt);
```

[矩陣] += -= *= [矩陣]: A += B 代表把矩陣 A 的內容設定成「矩陣A + 矩陣B」，其他依此類推。 
```
Matrix& operator+=(const Matrix& m)
Matrix& operator-=(const Matrix& m)
Matrix& operator*=(const Matrix& m)
```

[矩陣] *= [常數]: A *= B 代表把矩陣 A 的內容設定成「矩陣A *常數B」。 
```
Matrix& operator*=(double s)
```