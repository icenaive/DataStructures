#ifndef MY_TREE_WITH_LIST_
#define MY_TREE_WITH_LIST_

#include <iostream>
#include <cmath>
#include <string>
#include <queue>

#ifndef MAXN
#define MAXN 1000
#endif // MAXN

struct MyTreeListNode{
    char val;
    MyTreeListNode *lchild, *rchild;
};

class MyTreeList {
public:
    MyTreeList() {
        head = create_tree(head);
    }
    ~MyTreeList() {release(head);};
public:
    MyTreeListNode* create_tree(MyTreeListNode *t);
    int binary_tree_depth(MyTreeListNode *t);
    void pre_order_vis(MyTreeListNode *t);
    void in_order_vis(MyTreeListNode *t);
    void post_order_vis(MyTreeListNode *t);
    void lever_order();
    MyTreeListNode* get_head() {return head;}
private:
    void lever_order(MyTreeListNode *t);
    void release(MyTreeListNode *t);
    MyTreeListNode *head;
};

// 链表需要连接上
MyTreeListNode* MyTreeList::create_tree(MyTreeListNode *t) {
    char ch;
    std::cin >> ch;
    if(ch == '*') {
        t = nullptr;
    } else {
        t = new MyTreeListNode();
        t->val = ch;
        t->lchild = create_tree(t->lchild);
        t->rchild = create_tree(t->rchild);
    }
    return t;
}


int MyTreeList::binary_tree_depth(MyTreeListNode *t) {
    int i, j;
    if(!t) return 0;
    if(t->lchild) i = binary_tree_depth(t->lchild);
    else i = 0;
    if(t->rchild) j = binary_tree_depth(t->rchild);
    else j = 0;
    return i > j ? i + 1 : j + 1;
}
void MyTreeList::pre_order_vis(MyTreeListNode *t) {
    if(!t) return ;
    std::cout << t->val << " ";
    pre_order_vis(t->lchild);
    pre_order_vis(t->rchild);
}

void MyTreeList::in_order_vis(MyTreeListNode *t) {
    if(!t) return ;
    in_order_vis(t->lchild);
    std::cout << t->val << " ";
    in_order_vis(t->rchild);
}
void MyTreeList::post_order_vis(MyTreeListNode *t) {
    if(t == nullptr) return ;
    post_order_vis(t->lchild);
    post_order_vis(t->rchild);
    std::cout << t->val << " ";
}

void MyTreeList::lever_order() {
    lever_order(head);
}
void MyTreeList::lever_order(MyTreeListNode *t) {
    std::queue<MyTreeListNode*> q;
    q.push(t);
    while(!q.empty()) {
        std::cout << q.front()-> val << " ";
        t = q.front();
        if(t->lchild) q.push(t->lchild);
        if(t->rchild) q.push(t->rchild);
        q.pop();
    }
}
void MyTreeList::release(MyTreeListNode *t) {
    if(t) {
        release(t->lchild);
        release(t->rchild);
        delete t;
    }
}
#endif // MY_TREE_WITH_LIST_