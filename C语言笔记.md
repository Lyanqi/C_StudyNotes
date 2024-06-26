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
参考 https://developer.aliyun.com/article/1191956
```
>> 右移操作符
<< 左移操作符
```


与&，或|，异或^ 操作符，按二进制位进行操作（0为假，非0为真）

异或^：对应的二进制位相同，则运算结果为0；对应的二进制位不同，则运算结果为1   
```c
//一道应用异或的笔试题：要求不能创建临时变量（第三个变量），实现两个数的互换
int a = 3;
int b = 5;
a = a ^ b;//a为6
b = a ^ b;//b为3
a = a ^ b;//a为5
printf("a=%d\n", a);//结果:a=5
printf("b=%d\n", b);//结果:b=3
```


~：对一个数的二进制按位取反
```c
int a = 0;
int b = ~a;  //b是有符号的整型，二进制最高位0表示是正数，1表示是负数
printf("%d\n", b);   //运行结果是-1，因为这里打印的是b这个数的源码
```

负数在内存中存储的时候，存储的是二进制的补码

原码：直接按照正负写出的二进制序列

反码：正数的反码就是其原码；负数的反码是将原码的符号位不变，其他位取反

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


循环相关的关键字：   
break：循环中只要遇到break就停止后期所有循环，直接终止循环

continue：用于终止本次循环，本次循环continue后面的代码不再执行，而是直接进入下一次循环的入口判断

<font color='yellow'> 函数的链式访问： </font>   
把一个函数的返回值作为另一个函数的参数    
例子：    
```c
printf("%d\n",strlen("abc"));//结果：3
```
函数的声明定义使用：

![函数](pic/函数声明定义使用.png "函数声明定义使用" )     

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
	
	int i = 0;//确定冒泡排序的趟数
	for (i = 0; i < sz-1; i++)
	{
		int flag = 1;//假设这一趟要排序的数据已经有序
		int j = 0;
		for (j = 0; j<sz-1-i ; j++)
		{
			if (arr[j]>arr[j+1])
			{			
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;//本趟排序的数据其实不完全有序
			}
		}
		if (flag==1)
		{
			break;
		}
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

数组名代表数组首元素的地址，但是有两个特殊情况：   
1.sizeof(数组名)-数组名表示整个数组，计算的是整个数组的大小，单位是字节   
2.&数组名-数组名表示整个数组，计算的是整个数组的地址，单位是字节   
可以参考下面的代码
```c
int arr[] = {10,9,8,6,7,5,4,3,2,1};
printf("%p\n", arr);//结果：0000000A2C99FC58
printf("%p\n", arr+1);//结果：0000000A2C99FC5C

printf("%p\n", &arr[0]);//结果：0000000A2C99FC58
printf("%p\n", &arr[0]+1);//结果：0000000A2C99FC5C

printf("%d\n", *arr);//结果：10

printf("%p\n", &arr);//结果：0000000A2C99FC58
printf("%p\n", &arr+1);//结果：0000000A2C99FC80

//打印 arr 和 &arr[0]的结果，可以发现，arr和&arr[0]的地址是一样的；
//打印 arr+1 和&arr[0]+1 的结果，也是一样的，说明数组名就是首元素的地址
//打印 &arr 的结果，可以发现和 arr、&arr[0]的结果也一样，但是注意 &arr代表的是整个元素的地址，所以 &arr+1 的结果是加上了40个字节(数组有10个元素，每个元素4个字节)
//0000000A2C99FC80 = 43697962112(Base 10)
//0000000A2C99FC58 = 43697962072(Base 10)
//43697962112 − 43697962072 = 40(Base 10) = 28(Hex)
```


<font color='yellow'> 操作符详解： </font>  
取模操作符%，左操作数和右操作数必须是整数，结果是余数
```c
float a = 5 % 2;
printf("a=%lf", a); //结果：a=1.000000
```
逻辑与操作符&&
```c
int i = 0, a = 0, b = 2, c = 3, d = 4;
i = a++ && ++b && d++;

printf("a=%d\nb=%d\nc=%d\nd=%d\n", a,b,c,d);
//结果是：a=1 b=2 c=3 d=4
//因为a++是先使用再计算，所以第二行表达式里是 i=0 && ++b && d++,表达式结果已经是0了，所以后面就不算了
```

隐式转换-整型提升：   
C语言的整型算术运算总是至少以缺省整型类型的精度来进行的，为了获得这个精度，表达式中的字符（char）和短整型（short）操作数在使用之前被转换为普通整型（int），这种转换称为**整型提升**
```c
char a = 1;
printf("%d\n", sizeof(a));//结果:1
printf("%d\n", sizeof(+a));//+a的意思是正a，这里进行了整型提升，所以结果:4
printf("%d\n", sizeof(!a));//!是逻辑操作符，不是算术操作符，不会进行整型提升，结果:1
```

<font color='yellow'> 指针： </font>  
  指针是编程语言中的一个对象，利用地址，它的值直接指向存在电脑存储器中另一个地方的值。由于通过地址能找到所需的变量单元，可以说地址指向该变量单元。因此，将地址形象化的称为“指针”。意思是通过它能找到以它为地址的内存单元。
```c
int a = 10;
int* p = &a;    //p存放的是变量a的内存地址
*p = 20;    //通过p找到a，重新赋值
printf("%p\n", p);    //打印p存放的地址值
printf("%d\n", a);    //结果：20
```
指针是用来存放地址的，地址是唯一标识一块地址空间的   
指针大小在32位平台是4个字节，在64位平台是8个字节