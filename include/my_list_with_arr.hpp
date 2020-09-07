/*
 * @Date: 2020-09-07 01:29:33
 * @LastEditors: lizhe
 * @LastEditTime: 2020-09-07 04:17:20
 * @FilePath: /DataStructures/include/my_list_with_arr.hpp
 */
// 优点：在插入删除中修改下标，改进了顺序结构中需要移动大量元素的缺点
// 缺点：没有解决连续存储分配的表长难以确定的问题;失去了顺序存储结构随机存取的特性
#ifndef MY_LIST_WITH_ARR_
#define MY_LIST_WITH_ARR_
#ifndef MAXN
#define MAXN 1000
#endif // MAXN

#include <iostream>
struct MyListArrNode {
    int element;
    int next;
    MyListArrNode(int ele = 0, int n = 0) : element(ele), next(n) {} 
};

class MyListArr {
public:
    // 初始化
    MyListArr() : size(0) {
        int i = 0; 
        for(; i < MAXN - 1; ++i) arr[i].next = i + 1;
        arr[MAXN - 1] = 0;
    }
public:
    bool is_empty();
    void insert_node(int pos, int val);
    void delete_node(int pos);
    void print_node();
private:
    int malloc_node();
    void free_node(int k);
private:
    int size;
    MyListArrNode arr[MAXN];
};

inline bool MyListArr::is_empty() {
    return size == 0;
}

inline int MyListArr::malloc_node() {
    // 获取第一个空的位置
    int i = arr[0].next;
    // 如果拿走了 需要补上一个
    if(i) {
        arr[0].next = arr[i].next;
    }
    return i;
}

inline void MyListArr::free_node(int k) {
    arr[k].next = arr[0].next;
    arr[0].next = k;
}

void MyListArr::insert_node(int pos, int val) {
    int j, k, l;
    k = MAXN - 1;
    if(pos < 1 || pos > size + 1) {
        std::cerr << "error pos\n";
        return ;
    }
    j = malloc_node();
    if(j) {
        for(int i = 1; i < pos; ++i) {
            k = arr[k].next;
        }
        arr[j].next = arr[k].next;
        arr[k].next = j;
        arr[j].element = val;
        ++size;
    }
}

void MyListArr::delete_node(int pos) {
    int j, k, l;
    k = MAXN - 1;
    if(pos < 1 || pos > size + 1) {
        std::cerr << "error pos\n";
        return ;
    }
    for(int i = 1; i < pos; ++i) {
        k = arr[k].next;
    }
    j = arr[k].next;
    arr[k].next = arr[j].next;
    free_node(j);
    --size;
} 

void MyListArr::print_node() {
    int k = MAXN - 1;
    while(arr[k].next != 0) {
        std::cout << arr[k].element << " ";
        k = arr[k].next;
    }
    std::cout << std::endl;
}
#endif // MY_LIST_WITH_ARR_