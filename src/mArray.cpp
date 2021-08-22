#include "mArray.h"

const int initSize = 40;

// 无参构造
mArray::mArray()
{
    this->current = 0;
    this->length = initSize;
    this->array = new int[initSize]{};
}

// 有参构造
mArray::mArray(int len) : length(len)
{
    this->current = 0;
    this->array = new int[len]{};
}

// 拷贝构造
mArray::mArray(const mArray &arr)
{
    this->current = arr.current;
    this->length = arr.length;
    this->array = new int[this->length];
    for (int i = 0; i < this->length; ++i)
    {
        this->array[i] = arr.array[i];
    }
}

// 析构函数
mArray::~mArray()
{
    delete[] this->array;
    this->array = nullptr;
}

// 从后添加
void mArray::push_back(int value)
{
    if (this->current >= this->length)
    {
        this->resize(this->length * 2);
    }
    this->array[this->current++] = value;
}

// 从前添加
void mArray::push_front(int value)
{
    if (this->current >= this->length)
    {
        this->resize(this->length * 2);
    }

    // 所有元素后移
    for (int i = this->length - 1; i >= 0; --i)
    {
        this->array[i] = this->array[i - 1];
    }

    this->array[0] = value;
    --this->current;
}

// 反转
void mArray::reverse()
{
    for (int i = 0; i < this->length / 2; ++i)
    {
        int tmpValue = this->array[this->length - 1 - i];
        this->array[this->length - 1 - i] = this->array[i];
        this->array[i] = tmpValue;
    }
}

// 扩容
void mArray::resize(int newLength)
{
    if (newLength > this->length)
    {
        int *pointer = new int[newLength]{};
        for (int i = 0; i < this->length; ++i)
        {
            pointer[i] = this->array[i];
        }
        delete[] this->array;
        this->array = pointer;
        this->length = newLength;
        pointer = nullptr;
    }
}

// 弹出尾值
int mArray::pop()
{
    int popValue = this->array[--this->current];
    this->array[this->current] = 0;
    return popValue;
}

// 赋值重载
mArray mArray::operator=(const mArray &arr)
{
    return mArray(arr);
}

// 排序
void mArray::sort(bool (*compare)(int, int))
{
    for (int i = 0; i < this->length; ++i)
    {
        for (int j = i; j < this->length; ++j)
        {
            if (compare(this->array[i], this->array[j]))
            {
                int tmpValue = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = tmpValue;
            }
        }
    }
}

void mArray::print()
{
    cout << "length:" << this->length << endl;
    cout << "current:" << this->current << "\t" << this->array[this->current] << endl;
    for (int i = 0; i < this->length; i++)
    {
        cout << this->array[i] << " ";
    }
    cout << endl;
}