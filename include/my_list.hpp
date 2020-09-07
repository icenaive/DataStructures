/*
 * @Date: 2020-09-06 14:02:58
 * @LastEditors: lizhe
 * @LastEditTime: 2020-09-06 17:05:22
 * @FilePath: /DataStructures/include/my_list.hpp
 */
#ifndef MY_LIST_H__
#define MY_LIST_H__

#include <iostream>
struct MyListNode{
    int element;
    MyListNode *next;
    MyListNode(int ele = 0) : element(ele), next(nullptr) {}
};

class MyList {
public:
    MyList() : size(0), head_(nullptr), tail_(nullptr) {}
    ~MyList();
public:
    bool is_empty();
    void insert_front(int val);
    void insert_back(int val);
    void insert_node(int pos, int val);
    void delete_node(int pos);
    void update_node(int pos, int val);
    void print_list();
    MyListNode *find_node(int val);
private:
    int size;
    MyListNode *head_;
    MyListNode *tail_;
};

MyList::~MyList() {
    if(size == 0) {
        return ;
    } else {
        MyListNode *ptr = head_;
        while(ptr != nullptr) {
            MyListNode *temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        head_ = tail_ = nullptr;
    }
}
inline bool MyList::is_empty() {
    return size == 0;
}
// 头插入
void MyList::insert_front(int val) {
    if(size == 0) {
        head_ = tail_ = new MyListNode(val); 
    } else {
        MyListNode *ptr = new MyListNode(val);
        ptr->next = head_;
        head_ = ptr;
    }
    ++size;
}
// 尾插入
void MyList::insert_back(int val) {
    if(size == 0) {
        head_ = tail_ = new MyListNode(val);
    } else {
        tail_->next = new MyListNode(val);
        tail_ = tail_->next;
    }
    ++size;
}
// 在之前插入
void MyList::insert_node(int pos, int val) {
    if(size <= pos || pos < 0) {
        std::cerr << "插入位置超过链表长度" << std::endl;
        exit(1);
    } else {
        MyListNode *ptr = head_;
        for(int i = 0; i < pos; ++i) {
            ptr = ptr->next;
        }
        MyListNode *temp = new MyListNode(val);
        temp->next = ptr->next;
        ptr->next = temp;
        ++size;
    }
}

// 删除节点
void MyList::delete_node(int pos) {
    if(size <= pos || pos < 0) {
        std::cerr << "删除位置不对" << std::endl;
        exit(1);
    } else {
        MyListNode *ptr = head_;
        for(int i = 0; i < pos; ++i) ptr = ptr->next;
        MyListNode *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete(temp);
        --size;
    }
}
// 更新节点
void MyList::update_node(int pos, int val) {
    if(size <= pos || pos < 0) {
        std::cerr << "更新位置不对" << std::endl;
        exit(1);
    } else {
        MyListNode *ptr = head_;
        for(int i = 0; i < pos; ++i) ptr = ptr->next;
        ptr->next->element = val;
    }
}
// 打印
void MyList::print_list() {
    MyListNode *ptr = head_;
    while(ptr != nullptr) {
        std::cout << ptr->element << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
// 查找结点
MyListNode *MyList::find_node(int val) {
    if(size == 0) {
        return nullptr;
    } else {
        MyListNode *ptr = head_;
        while( ptr!= nullptr) {
            if(ptr->element == val) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return ptr;
    }
}

#endif /*MY_LIST_H__*/