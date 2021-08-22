#include "iostream"
#include "array2.cpp"
// #include "mArray.h"
using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    mArray arr;
    arr.push_back(10);
    arr.push_front(20);
    arr.push_back(40);
    arr.push_back(-1);
    arr.print();

    // int popValue = arr.pop();
    // cout << "pop value:" << popValue << endl;

    // arr.print();
    // arr.reverse();
    // mArray newArr = arr;
    // newArr.print();

    arr.resize(80);
    arr.sort(compare);

    arr.print();

    return 0;
}