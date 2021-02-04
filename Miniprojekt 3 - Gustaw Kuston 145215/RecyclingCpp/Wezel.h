#include <iostream>
#include <memory>
#ifndef WEZEL_H
#define WEZEL_H

class Wezel {
    private:
    public:
    std::weak_ptr<Wezel> next;
    ~Wezel();
};

#endif
