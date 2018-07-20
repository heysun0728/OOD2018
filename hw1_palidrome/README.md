# palindrome

### 1. 以 C++ 撰寫 判斷迴文(palindrome)的程式

(迴文代表「從左到右」和「從右到左」的字母順序都相同，

例如<code> A man, a plan, a canal: Panama!</code> 這段文字不論正反都是 A M A N A ...)

程式必須用引數(argument)的方式讓使用者輸入一段文字，

判斷這段文字是否為迴文，如果是迴文的話，印出 Yes，否則印出 No。

例如:
使用者輸入 a.out "A man, a plan, a canal: Panama!" 時，程式應該印出 Yes

判斷條件如下:

1. 忽略所有的空白和標點符號

2. 不分大小寫 (ex. Aha應該判斷為迴文，即使 大寫A 和 小寫a 不同)

3. 數字 不論「納入迴文判斷條件」或是「忽略」都給對


### 2. 以 Java 撰寫 判斷迴文的程式

判斷條件和 C++ 的程式相同

### 3. MakeFile
(1) 當使用者輸入 make 時，可以從你的 source code 編譯出 .out 執行檔 (在 Windows 下是 .exe)

(2) 當使用者輸入 make clean 時，可以把所有的中間檔 (例如 .o) 和執行檔 (.out) 清除。

### 4. 範例
<pre><code>WOW -- Yes
example -- No
Radar -- Yes
kamehameha -- No
1234ccc4321 -- Yes
aha! -- Yes
Damon has a pet dog. -- No
Meet animals; laminate em. -- Yes
</pre></code>
