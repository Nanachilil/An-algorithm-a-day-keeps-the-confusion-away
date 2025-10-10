#include <cstdio>
// #include <iostream>

int value1 = 1;
int value2 = 1;

int CallBack1()
{
    return value1;
}

int &CallBack2()
{
    return value2;
}

int main()
{
    int cb1;
    cb1 = CallBack1();      // 普通的赋值
    int &cb2 = CallBack2(); // 引用的初始化，必须在定义时初始化

    // 改变 cb1 和 cb2 的值
    cb1 = 100;
    cb2 = 200;

    std::printf("cb1 = %d, cb2 = %d\n", cb1, cb2);
    std::printf("value1 = %d, value2 = %d\n", value1, value2);
}
