#ifndef MY_THREAD_TREE_
#define MY_THREAD_TREE_

#include <iostream>

struct MyThreadTreeNode {
    char val;
    MyThreadTreeNode *lchild, *rchild;
    bool ltag, rtag;
    MyThreadTreeNode(const char &item) :val(item), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {}  //结点类的构造函数
};

class MyThreadTree {
public:
    MyThreadTree() {
        create_tree(head);
    }
    void in_order_vis();
    void create_thread_in();
    void create_thread_in(MyThreadTreeNode *cur, MyThreadTreeNode *pre);
private:    
    void in_order_vis(MyThreadTreeNode*);
    void create_tree(MyThreadTreeNode *&t);
private:
    MyThreadTreeNode *head;
};

void MyThreadTree::create_tree(MyThreadTreeNode *&t) {
    char ch;
    std::cin >> ch;
    if(ch != '*') {
        t = new MyThreadTreeNode(ch);
        if(t == nullptr) {
            std::cout << "kong jian fen pei cuo wu\n";
            exit(1);
        }
        create_tree(t->lchild);
        create_tree(t->rchild);
    } else {
        t == nullptr;
    }
}

void MyThreadTree::in_order_vis() {
    in_order_vis(head);
}

void MyThreadTree::in_order_vis(MyThreadTreeNode *t) {
    if(t != nullptr) {
        std::cout << t->val << " ";
        in_order_vis(t->lchild);
        in_order_vis(t->rchild);
    }
}
void MyThreadTree::create_thread_in() {
    MyThreadTreeNode *pre = nullptr;
    if(!head) {
        create_thread_in(head, pre);
    }
}

void MyThreadTree::create_thread_in(MyThreadTreeNode *cur, MyThreadTreeNode *pre) {
    if(cur == nullptr) return ;
    create_thread_in(cur->lchild, pre);
    if(!cur->lchild) {
        cur->lchild = pre;
        cur->ltag = 1;
    }
    if(pre != nullptr && cur->rchild == nullptr) {
        pre->rchild = cur;
        pre->rtag = 1;
    }
    pre = cur;
    create_thread_in(cur->rchild, pre);
}
#endif // MY_THREAD_TREE_