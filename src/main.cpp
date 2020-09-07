/*
 * @Date: 2020-09-06 13:02:41
 * @LastEditors: lizhe
 * @LastEditTime: 2020-09-07 11:02:13
 * @FilePath: /DataStructures/src/main.cpp
 */
#include "../include/my_list.hpp"
#include "../include/my_double_list.hpp"
#include "../include/my_list_with_arr.hpp"
#include "../include/my_stack_with_arr.hpp"
#include "../include/my_queue_with_arr.hpp"
using namespace std;

void test_my_list();
void test_my_double_list();
void test_my_list_arr();
void test_my_stack_arr();
void test_my_queue_arr();

int main() {
    // 测试链表
    /// test_my_list();
    // 测试双链表
    /// test_my_double_list();
    // 测试静态链表
    /// test_my_list_arr();
    // 测试栈
    /// test_my_stack_arr();
    // 测试队列
    test_my_queue_arr();
    return 0;
}

void test_my_list() {
    MyList *ptr = new MyList();
    MyListNode *find_ptr;
    cout << "is_empty: "<< ptr->is_empty() << endl;
    ptr->insert_front(1);
    cout << "is_empty: "<< ptr->is_empty() << endl;
    ptr->print_list();
    find_ptr = ptr->find_node(1);
    cout << find_ptr->element << endl;
    ptr->insert_front(2);
    ptr->print_list();
    ptr->insert_back(4);
    ptr->print_list();
    ptr->insert_node(2, 4);
    ptr->print_list();
    ptr->delete_node(2);
    ptr->update_node(1, 5);
    ptr->print_list();
}
void test_my_double_list() {
    MyDoubleList *ptr = new MyDoubleList();
    MyDoubleListNode *find_ptr;
    cout << "is_empty: "<< ptr->is_empty() << endl;
    ptr->insert_front(1);
    ptr->insert_front(2);
    ptr->insert_front(3);
    ptr->print_list_front();
    ptr->print_list_back();
    find_ptr = ptr->find_node(1);
    cout << find_ptr->element << endl;
    ptr->insert_back(4);
    ptr->print_list_front();
    ptr->insert_node(2, 5);
    ptr->print_list_front();
    ptr->update_node(1, 7);
    ptr->print_list_front();
}
void test_my_list_arr() {
    MyListArr arr;
    cout << arr.is_empty() << endl;
    arr.insert_node(1, 0);
    arr.insert_node(1, 2);
    arr.insert_node(1, 3);
    arr.print_node();
    arr.delete_node(1);
    arr.print_node();
}

void test_my_stack_arr() {
    MyStackArr s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.get_pop() << endl;
    s.pop();
    cout << s.get_pop() << endl;
}

void test_my_queue_arr() {
    MyQueueArr q;
    q.push(1);
    q.push(2);
    cout << q.size() << endl;
    cout << q.pop() << endl;
    q.push(3);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
}