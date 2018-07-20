# word_locator

### 1. 啟動

啟動程序時，顯示 > 符號 或 適當文字 來提示使用者輸入

### 2. load 
使用者輸入load <filename>時，載入文字檔，例如 

<pre><code>load sixpence.txt </code></pre>

### 3. locate 
當使用者輸入
<pre><code>locate (word) (n) </code></pre>
可以查詢 (word) 的第 (n) 次出現是在文章的第幾個單詞。

特殊符號(逗點、句點、問號等)不算作單詞的一部分，

但是單引號(') 算作單詞的一部分，例如 wasn't 應該是一整個單詞。

換句話說，除了單引號、字母、數字之外的所有字元 (" : ; ' [ ] { } _ = + - * % / \ ~ ` 等)，都不算作單詞的一部分。

數字的處理方式以「是否有空格斷開」判斷:

<pre><code>Hello 123 world，123 算是第2個單詞。

Hello 123world，123world 算是第2個單詞。 </code></pre>

locate 不區分大小寫 有區分大小寫 

(當使用者要找 Flower 時，你的程式應該要能找到 Flower，但不應該找到 flower)

＊ 請加上適當的「防呆措施」。
(例如使用者輸入 "locate pie pppp" 或 "locate pie -2" 時，程式不能當掉。)

### 4. new
使用者輸入 new 時會重置單詞列表(把單詞列表清空)，讓使用者可以重新 load 文件一次。

### 5. end
使用者輸入end會中止程式

### 6.錯誤提示 
1. locate 找不到單詞時顯示 No matching entry
命令有區分大小寫 (也就是說，你的程式只需要處理 locate，而不用處理 Locate、locate、loCATE、...)
2. 輸入錯誤或無關指令(例如: find word 7) 顯示 ERROR: Invalid command
3. load 文字檔時，如果找不到檔案(或是無法讀取) 則提示 ERROR: Error reading from file。
如果找不到檔案，則提示 ERROR: File not found
讀取錯誤則提示 ERROR: Error reading from file

### 7. MakeFile 
並且當使用者輸入 make 時，可以從你的 source code 編譯出執行檔。

### 8. 範例
input:
<pre><code>Sing a song of sixpence,
A pocket full of rye;
Four and twenty blackbirds
Baked in a pie.
When the pie was opened,
They all began to sing.
</code></pre>
output:
<pre><code>>load sixpence.txt
>locate pocket 1
7
>locate pie 2
21
>locate Pocket 1
No matching entry
>new
>locate pocket 2
No matching entry
> locate
ERROR: Invalid command
>end
</code></pre>