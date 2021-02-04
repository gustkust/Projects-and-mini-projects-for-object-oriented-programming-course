#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#ifndef STACK_H
#define STACK_H

using namespace std;


class Stack {
private:
    int maxStackSize;
    vector<int> dfs;
    int top;
public:
    Stack();
    Stack(int max);
    void push(int newItem);
    void pop();
    int getSS();
};

#endif
