#ifndef MY_QUEUE_WITH_ARR_
#define MY_QUEUE_WITH_ARR_
#include <iostream>
#ifndef MAXN
#define MAXN 1000
#endif // MAXN

class MyQueueArr {
public:
    MyQueueArr() {
        head = rear = 0;
    }
public:
    int size();
    void push(int val);
    int pop();
private:
    int element[MAXN];
    int head, rear;
};

inline int MyQueueArr::size() {
    return (rear - head + MAXN) % MAXN;
}

void MyQueueArr::push(int val) {
    if((rear + 1) % MAXN == head) {
        std::cerr << "queue is full\n";
        return ;
    } 
    element[rear] = val;
    rear = (rear + 1) % MAXN; 
}
int MyQueueArr::pop() {
    if(rear == head) {
        std::cerr << "queue is empty\n";
        exit(1);
    }
    int temp = head;
    head = (head + 1) % MAXN;
    return element[temp];
}
#endif // MY_QUEUE_WITH_ARR_