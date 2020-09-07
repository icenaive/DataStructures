/*
 * @Date: 2020-09-07 10:03:13
 * @LastEditors: lizhe
 * @LastEditTime: 2020-09-07 10:40:45
 * @FilePath: /DataStructures/include/my_stack_with_arr.hpp
 */
#ifndef MY_STACK_WITH_ARR_
#define MY_STACK_WITH_ARR_
#include <iostream>
#ifndef MAXN
#define MAXN 1000
#endif // MAXN

class MyStackArr {
public:
    MyStackArr(int t = -1) : top(t) {}
public:
    void push(int val);
    void pop();
    int get_pop();
    bool is_empty();
private:
    int top;
    int element[MAXN];
};

void MyStackArr::push(int val) {
    if(top == MAXN - 1) {
        std::cerr << "stack is full\n";
        return ;
    }
    element[++top] = val;
}
int MyStackArr::get_pop() {
    if(top == -1) {
        std::cerr << "stack is empty\n";
        exit(1);
    }
    return element[top];
}
void MyStackArr::pop() {
    if(top == -1) {
        std::cerr << "stack is empty\n";
        exit(1);
    }
    --top;
}
inline bool MyStackArr::is_empty() {
    return top == -1;
}
#endif // MY_STACK_WITH_ARR_