两个有用的网站：

https://cplusplus.com

https://zh.cppreference.com



extern关键词
```c
extern int i;//声明，不是定义
int i;//声明，也是定义
```

字符串的结束标志是一个\0的转义字符，计算字符串长度时\0不算作字符内容

移位操作符，就是把二进制值左移或右移
```
>> 右移操作符
<< 左移操作符
```


与&，或|，异或^ 操作符，按二进制位进行操作（0为假，非0为真）

异或^：对应的二进制位相同，则运算结果为0；对应的二进制位不同，则运算结果为1

~：对一个数的二进制按位取反
```c
int a = 0;
int b = ~a;  //b是有符号的整型，二进制最高位0表示是正数，1表示是负数
printf("%d\n", b);   //运行结果是-1，因为这里打印的是b这个数的源码
```

负数在内存中存储的时候，存储的是二进制的补码

原码：直接按照正负写出的二进制序列

反码：原码的符号位不变，其他位取反

补码：反码+1



*间接访问操作符（解引用操作符）

&取地址操作符

C语言关键字

register：寄存器变量修饰符，被修饰的变量只是尽可能被设置为寄存器变量，因为寄存器资源有限

unsigned：无符号

union：联合体/共用体

typedef：类型定义

例子：
```c
typedef unsigned int u_int;
u_int a = 3;
```


static修饰局部变量，局部变量的生命周期变长

static修饰全局变量，改变了变量的作用域，让静态的全局变量只能在自己所在的源文件内使用，出了源文件就没法再使用

指针
```c
int a = 10;
int* p = &a;    //p存放的是变量a的内存地址
*p = 20;    //通过p找到a，重新赋值
printf("%p\n", p);    //打印p存放的地址值
printf("%d\n", a);    //结果：20
```

指针大小在32位平台是4个字节，在64位平台是8个字节

break：循环中只要遇到break就停止后期所有循环，直接终止循环

continue：用于终止本次循环，本次循环continue后面的代码不再执行，而是直接进入下一次循环的入口判断

<font color='yellow'> 函数的链式访问： </font>   
把一个函数的返回值作为另一个函数的参数    
例子：    
```c
printf("%d\n",strlen("abc"));//结果：3
```
函数的声明定义使用：

![函数](/pic/函数声明定义使用.png "函数声明定义使用" )     

<font color='yellow'> 函数递归： </font>   
程序调用自身的编程技巧称为递归   
递归有两个必要条件：   
1. 存在限制条件，当满足限制条件时，递归结束   
2. 每次递归调用时，问题规模相比上次递归调用时有所减少   

例子：   
```c
//将输入的数字每一位打印出来，用空格分隔
void print（int n）
{
    if(n>9)
    {
        print(n/10);
    }
    printf("%d ",n%10);
}
int main()
{
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
//输入1234
//输出结果：1 2 3 4
```

求解斐波那契数列的第n个数字：   
如果用递归求解，会重复计算很多次，效率低   
用循环求解，效率比较高
```c
int Fun(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fun(n);
	printf("%d", ret);
}
//输入10
//输出结果：55
```

<font color='yellow'> 冒泡排序： </font>  
```c
//冒泡排序函数
void Fun(int arr[],int sz)
{
	
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j<sz-1 ; j++)
		{
			if (arr[j]>arr[j+1])
			{			
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for (int n = 0; n < sz; n++)
	{
		printf("%d ", arr[n]);
	}
}
int main()
{
	
	int arr[] = {10,9,8,6,7,5,4,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	Fun(arr,sz);
}
//输出结果：1 2 3 4 5 6 7 8 9 10
```
