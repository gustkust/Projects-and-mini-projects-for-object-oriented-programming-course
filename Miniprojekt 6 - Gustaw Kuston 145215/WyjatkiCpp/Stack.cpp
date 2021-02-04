#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Stack.h"
#include "StackException.h"
#include "StackFullException.h"
#include "StackEmptyException.h"


using namespace std;


Stack::Stack() {
    maxStackSize = 3;
    top = 0;
}

Stack::Stack(int max) {
    maxStackSize = max;
    top = 0;
}

void Stack::push(int newItem) {
    if (dfs.size() >= maxStackSize) {
        StackFullException e("", newItem, maxStackSize);
        throw e;
    }
    dfs.push_back(newItem);
}

void Stack::pop() {
    if (dfs.size() == 0) {
        StackEmptyException e;
        throw e;
    }
    dfs.pop_back();
}

int Stack::getSS() {
    return maxStackSize;
}