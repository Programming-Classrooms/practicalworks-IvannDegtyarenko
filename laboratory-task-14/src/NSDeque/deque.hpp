#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <typeinfo>

template<typename TInfo>
class TDeque
{
private:

struct TDequeItem 
{
    TInfo info;
    TDequeItem* next;
    TDequeItem* prev;

    TDequeItem();
    TDequeItem(TInfo);
    ~TDequeItem();

    TDequeItem& operator=(TInfo);
    TDequeItem& operator=(const TDequeItem&);
};


TDequeItem *front, *rear;

int size;
void Erase();
void Clone(const TDeque&);
void DeleteItem(TDequeItem*);
TDequeItem* PtrByIndex(size_t)const;

public:

TDeque();
TDeque(const TDeque&);
virtual ~TDeque();

void InsertFront(const TInfo&);
void InsertRear(const TInfo&);
bool DeleteFront();
bool DeleteRear();

const TDeque& operator=(const TDeque&);
const TInfo& GetInfoByIndex(size_t)const;
void SetInfoByIndex(TInfo, size_t);
void BrowseNChange(void view(TInfo));
void BrowseDnChange(void view(TInfo)) const;
};

#include "deque.inl"

#endif //DEQUE_HPP
