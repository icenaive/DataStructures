/*
 * @Date: 2020-09-06 14:02:58
 * @LastEditors: lizhe
 * @LastEditTime: 2020-09-06 17:19:18
 * @FilePath: /DataStructures/include/my_double_list.hpp
 */
#ifndef MY_DOUBLE_LIST_H__
#define MY_DOUBLE_LIST_H__

#include <iostream>
struct MyDoubleListNode{
    int element;
    MyDoubleListNode *next;
    MyDoubleListNode *prev;
    MyDoubleListNode(int ele = 0) : element(ele), next(nullptr), prev(nullptr) {}
};

class MyDoubleList {
public:
    MyDoubleList() : size(0), head_(nullptr), tail_(nullptr) {}
    ~MyDoubleList();
public:
    bool is_empty();
    void insert_front(int val);
    void insert_back(int val);
    void insert_node(int pos, int val);
    void delete_node(int pos);
    void update_node(int pos, int val);
    void print_list_front();
    void print_list_back();
    MyDoubleListNode *find_node(int val);
private:
    int size;
    MyDoubleListNode *head_;
    MyDoubleListNode *tail_;
};

MyDoubleList::~MyDoubleList() {
    if(size == 0) {
        return ;
    } else {
        MyDoubleListNode *ptr = head_;
        while(ptr != nullptr) {
            MyDoubleListNode *temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        head_ = tail_ = nullptr;
    }
}
inline bool MyDoubleList::is_empty() {
    return size == 0;
}
// 头插入
void MyDoubleList::insert_front(int val) {
    if(size == 0) {
        head_ = tail_ = new MyDoubleListNode(val); 
    } else {
        MyDoubleListNode *ptr = new MyDoubleListNode(val);
        ptr->next = head_;
        head_->prev = ptr;
        head_ = ptr;
    }
    ++size;
}
// 尾插入
void MyDoubleList::insert_back(int val) {
    if(size == 0) {
        head_ = tail_ = new MyDoubleListNode(val);
    } else {
        tail_->next = new MyDoubleListNode(val);
        tail_->next->prev = tail_;
        tail_ = tail_->next;
    }
    ++size;
}
// 在之前插入
void MyDoubleList::insert_node(int pos, int val) {
    if(size <= pos || pos < 0) {
        std::cerr << "插入位置超过链表长度" << std::endl;
        exit(1);
    } else {
        MyDoubleListNode *ptr = head_;
        for(int i = 0; i < pos; ++i) {
            ptr = ptr->next;
        }
        MyDoubleListNode *temp = new MyDoubleListNode(val);
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
        temp->prev = ptr;
        ++size;
    }
}

// 删除节点
void MyDoubleList::delete_node(int pos) {
    if(size <= pos || pos < 0) {
        std::cerr << "删除位置不对" << std::endl;
        exit(1);
    } else {
        MyDoubleListNode *ptr = head_;
        for(int i = 0; i < pos; ++i) ptr = ptr->next;
        MyDoubleListNode *temp = ptr->next;
        ptr->next = ptr->next->next;
        ptr->next->next->prev = ptr;
        delete(temp);
        --size;
    }
}
// 更新节点
void MyDoubleList::update_node(int pos, int val) {
    if(size <= pos || pos < 0) {
        std::cerr << "更新位置不对" << std::endl;
        exit(1);
    } else {
        MyDoubleListNode *ptr = head_;
        for(int i = 0; i < pos; ++i) ptr = ptr->next;
        ptr->next->element = val;
    }
}
// 打印
void MyDoubleList::print_list_front() {
    MyDoubleListNode *ptr = head_;
    while(ptr != nullptr) {
        std::cout << ptr->element << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
// 打印
void MyDoubleList::print_list_back() {
    MyDoubleListNode *ptr = tail_;
    while(ptr != nullptr) {
        std::cout << ptr->element << " ";
        ptr = ptr->prev;
    }
    std::cout << std::endl;
}
// 查找结点
MyDoubleListNode *MyDoubleList::find_node(int val) {
    if(size == 0) {
        return nullptr;
    } else {
        MyDoubleListNode *ptr = head_;
        while( ptr!= nullptr) {
            if(ptr->element == val) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return ptr;
    }
}

#endif /*MY_DOUBLE_LIST_H__*/