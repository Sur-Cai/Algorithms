#ifndef LINEARLIST_H_INCLUDED
#define LINEARLIST_H_INCLUDED
#include "iterator.h"
template <class Item>
class Aggregate {
public:
    virtual ~Aggregate(){}

    virtual Iterator<Item>* CreateIterator() = 0;
    virtual int getLen() const = 0;
    virtual Item* getItem(int nIndex) const = 0;
};
#endif // LINEARLIST_H_INCLUDED
