# Clang-Study

该项目用于记录一些 C/C++ 的学习笔记，以及测试代码。
目前还是一些比较零散的知识点，后期还会不断更新，总结。

### C ++

#### 基本类型

- 缺省类型 void
- 算术类型 整型（字符，布尔）、浮点型

指针类型所占字节数与计算机位数相关

unsigned 无符号整型注意范围

判断浮点数是否相等：两数相减取绝对值，是否小于某一精度范围；

隐式类型转换：当变量定义赋值时与所其所声明的类型不一致；

字面值常量、转移字符

空指针：nullptr

列表初始化：int n = { 1 };
int n1(0);
int n2 = 2;
int n3 = { 3 };
int n4{4};

explicit 关键字，禁止隐式类型转换


#### 引用

引用是对象的别名，引用无法改变指向；

- 左值引用

```cpp
int x1 = 10;
int& x2 = x1;

// 常量左值引用
const int& i = 100;
```

- 右值引用，用于引用字面值，表达式和函数返回值；
  
```cpp
int&& n = 100;
```

常量左值引用可以接受左值和右值
常量右值引用只能接受右值
右值引用只能接受右值
左值引用只能接受左值
值传递可以接受左值和右值

#### 指针

指针本身是对象；通常初始为空指针；
引用和指针的区别：引用是一个 const 指针；

```cpp
// 指针初始化
int number = 3;
int* pointer = &number;

// 指针销毁
delete pointer;
pointer = nullptr;
```

```cpp
// 函数指针
int add(int a, int b){
    return a + b;
}

// 定义
int (*fp)(int a, int b) = &add;

// 调用
fp(1, 2);
(*fp)(2, 3);
```

#### const 常量

定义时赋初值，且初始化后无法改变值；

```cpp
// 常量指针，无法更改指向；
const int num = 80;
int* const ptr = &num;

// 指针常量，无法通过指针更改指向地址的值；
const int* ptr = &num;

// 指向常量的常量指针
const int* const ptr = &num;
```

更改常量的值，常量折叠，volatile
强制类型转换
<!-- const_cast<int*> -->

#### 类型别名

```cpp
typedef float mFloat;
using mInt = int; // c11
```

#### 宏定义

```cpp
#define mType long int
#undef mType

#endif
#define ADD(a, b) ((a) + (b))
```

预定义宏

```cpp
__DATE__
__FILE__
__LINE__
```

宏运算 # ##

自动类型
auto
类型推导
decltype(Function())
decltype(Varible)

头文件卫士
申明放在头文件中
定义放在源文件中；

#### 内存分区

- 栈区：由编译器自动分配地址，局部变量
- 堆区：手动分配释放
- 全局区（静态区）
- 常量区：存放常量
- 代码区：存放函数

低地址->高地址：代码区，常量区，全局区，堆区（↑），栈区（↓）

内存分配与释放

```cpp
int* p1 = new int{5};
int* p2 = new int[5]{}; // 自动初始化为 0

delete p1
delete[] p2
```

#### 函数

调用运算符 ()

```cpp
// 函数定义
int add(int a, int b) {
    return a + b;
}

// 仿函数
class A{
    int operator(int a, int b){
        return a + b;
    }
}

A a;
a(1, 2);
```

函数调用流程：

- 实参初始化函数对应的形参；
- 将控制权转移给被调用函数，入栈；
- 返回return语句中的值；
- 将控制权从被调函数转移回主调函数；

局部变量：形参和函数体内定义的变量称为局部变量；
局部变量在作用域结束时会被销毁，因此函数中不要返回指向局部变量的指针；
可以将局部变量定义为

单例模式：
在程序的执行路径第一次经过对象定义语句时初始化；

```cpp
// 仿函数
class Single{
private:
    Single() {}

public:
    static Single instance(){
        static Single* ins = nullptr;
        if (!ins){
            ins = new Single();
        }
        return ins;
    }
}

int main() {
    auto x = Single.instance()
    return 0;
}
```

函数重载

lambda函数：

捕获列表：[=]值传递方式调用外部变量；[&]引用方式调用外部变量
形参列表，
修饰符，mutable，可改值传递副本值
返回列表，
函数体，

```cpp
auto add = [](int a, int b)->int{
    return a+b;
}

auto add = [](int a, int b){
    return a+b;
}

auto add = [](){
    return 0;
}

auto add = []{};
```

#### 位运算符

- 按位取反 ~
- 左移 <<
- 右移 >>
- 按位与
- 按位

```cpp
1 ^ 2 == 2 ^ 1
0 ^ 1 == 1
```

#### 面向对象

三大特性

1. 数据封装
2. 继承
3. 多态

访问权限：public、protected、private
定义类：class（默认私有）、struct（默认共有）

构造函数：函数名同类名，可以重载，在创建对象时调用；调用无参构造函数不能加括号，编译器会认为有括号的为一个函数申明；不能利用拷贝构造函数初始化匿名对象；
析构函数：没有返回值，也不能有参数；
拷贝构造函数：使用一个已经创建完毕的对象来初始化一个新对象，使用值传递的方式给形参传值，以值传递方式返回一个局部对象；

默认情况下，编译器会自动添加无参构造函数，析构函数，拷贝构造函数和operator=重载函数；
如果用户提供有参构造，编译器则不添加默认构造，会提供拷贝构造函数；
如果用户提供拷贝构造，编译器不会添加其他构造函数；

浅拷贝：简单的赋值拷贝操作；
深拷贝：在堆区重新申请空间，进行拷贝构造；

如果类中申请了堆区中的内存，需要重写拷贝构造，否则会造成二次析构内存；

```cpp
class Person{
private:
    name: "Coley";

public:

    Person() {
    }
    ~Person() {
    }
    Person(const Person &p){
    }

}
```

初始化列表方式效率高，会比普通少调用一次默认构造函数；初始化顺序根据成员变量申明的顺序决定；
组合：类类型的成员变量；

静态变量和静态成员函数：有访问权限，静态成员函数无法访问非静态成员变量，因为没有this指针；

类内的成员变量和成员函数分开存储，只有非静态成员变量才属于类的对象上；
非静态成员变量占对象空间
静态成员变量不占对象空间

内存对齐

this指针：在成员函数调用前，由编译器自动添加
空指针也可访问成员函数，

作业：实现一个长度为400的自定义数组类
// push_back
// push_front
// append
// pop
// resize
// reverse
// sort
// operator=
// int* array = new int[400]{}

#### 常函数

成员函数后加 const，成为常函数，常函数内不可以修改成员属性，只能调用常函数，或者 mutable 标记的成员属性；

常对象：声明对象时添加 const 关键字；常对象只能调用常函数；

#### 友元

让函数或类访问另一个类中的私有成员；
三种友元实现：

- 友元全局函数
- 友元类
- 友元成员函数

类前置声明效率高于头文件引入

#### 运算符重载

无法对