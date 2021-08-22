#ifndef _MARRAY_
#define _MARRAY_
#include "iostream"
using namespace std;

class mArray
{
private:
    int length;  // 数组长度
    int current; // 当前索引
    int *array;  // 数组指针

public:
    mArray();
    mArray(int);
    mArray(const mArray &);
    ~mArray();
    void push_back(int);
    void push_front(int);
    void reverse();
    void resize(int);
    void sort(bool (*)(int, int));
    int pop();
    void print();
    mArray operator=(const mArray &);
};

#endif