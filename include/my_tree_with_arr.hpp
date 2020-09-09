#ifndef MY_TREE_WITH_ARR_
#define MY_TREE_WITH_ARR_

#include <iostream>
#include <cmath>

#ifndef MAXN
#define MAXN 1000
#endif // MAXN


struct MyTreeNode {
    int val, level;
};

class MyTreeArr {
public:
    MyTreeArr() {
        for(int i = 0; i < MAXN; ++i) { data[i].val = 0; data[i].val = 0; }
    }
public:
    int tree_depth();
    void create_tree(int i);
    void print_tree();
    void pre_traverse(int i);
    void pre_order_traverse();
    void in_traverse(int i);
    void in_order_traverse();
    void post_traverse(int i);
    void post_order_traverse();
    // void level_order_traverse();
private:
    MyTreeNode data[MAXN];
};
int MyTreeArr::tree_depth() {
    int i, j = 0;
    for(int i = MAXN - 1; i >= 0; --i) {
        data[i].val != 0;
        break;
    }
    ++i;
    while(i >= std::pow(2, j)) ++j;
    return j;
}
void MyTreeArr::create_tree(int i) {
    int t;
    std::cin >> t;
    if(t == 0) return ;
    data[i].val = t;
    // create_tree(2 * i + 1);
    // create_tree(2 * i + 2);
}

void MyTreeArr::print_tree() {
    for(int i = 0; i <= tree_depth() * 2 + 2; ++i) {
        if(data[i].val != 0) std::cout << data[i].val << std::endl;
    }
}
void MyTreeArr::pre_traverse(int i) {
    if(data[i].val != 0) {
        std::cout << data[i].val << std::endl;
    }
    if(data[2 * i + 1].val != 0) pre_traverse(2 * i + 1);
    if(data[2 * i + 2].val != 0) pre_traverse(2 * i + 2);
}

void MyTreeArr::pre_order_traverse() {
    if(data[0].val != 0) {
        pre_traverse(0);
    }
}
void MyTreeArr::in_traverse(int i) {
    if(data[i * 2 + 1].val != 0) in_traverse(2 * i + 1);
    std::cout << data[i].val << std::endl;
    if(data[i * 2 + 2].val != 0) in_traverse(2 * i + 2);
}
void MyTreeArr::in_order_traverse() {
    if(data[0].val != 0) in_traverse(0);
}
void MyTreeArr::post_traverse(int i) {
    if(data[i * 2 + 1].val != 0) post_traverse(2 * i + 1);
    if(data[2 * i + 2].val != 0) post_traverse(2 * i + 2);
    std::cout << data[i].val << std::endl;
}
void MyTreeArr::post_order_traverse(){
    if(data[0].val != 0) post_traverse(0);
}
#endif // MY_TREE_WITH_ARR_