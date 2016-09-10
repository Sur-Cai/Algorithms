#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED
template <class Item>
class Iterator {
public:
    virtual ~Iterator(){}

    virtual void  first()        = 0;
    virtual void  next()         = 0;
    virtual bool  isDone()       = 0;
    virtual Item* currentItem()  = 0;
};
#endif // ITERATOR_H_INCLUDED
