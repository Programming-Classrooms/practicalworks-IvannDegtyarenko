#include "deque.hpp"

template <typename TInfo>
TDeque<TInfo>::TDequeItem::TDequeItem() : info(TInfo()), next(nullptr), prev(nullptr) 
{}

template <typename TInfo>
TDeque<TInfo>::TDequeItem::TDequeItem(TInfo item) : info(item), next(nullptr), prev(nullptr)
{}

template<typename TInfo>
TDeque<TInfo>::TDequeItem::~TDequeItem()
{}

template<typename TInfo>
typename TDeque<TInfo>::TDequeItem& TDeque<TInfo>::TDequeItem::operator=(TInfo data)
{
    this->info = data;
    return *this;
}

template<typename TInfo>
typename TDeque<TInfo>::TDequeItem& TDeque<TInfo>::TDequeItem::operator=(const TDeque<TInfo>::TDequeItem& src) 
{
    this->info = src.info;
    return *this;
}

template<>
typename TDeque<char*>::TDequeItem& TDeque<char*>::TDequeItem::operator=(char* data)
{
    size_t dataLength = strlen(data);
    this->info = new char[dataLength + 1];
    strcpy(this->info, data);
    return *this;
}

template<>
typename TDeque<char*>::TDequeItem& TDeque<char*>::TDequeItem::operator=(const TDeque<char*>::TDequeItem& src) 
{
    size_t dataLength = strlen(src.info);
    this->info = new char[dataLength + 1];
    strcpy(this->info, src.info);
    return *this;
}

template<>
TDeque<char*>::TDequeItem::TDequeItem(char* item)
{
    size_t length = strlen(item);
    this->info = new char[length + 1];
    strcpy(this->info, item);
}

template<>
TDeque<char*>::TDequeItem::~TDequeItem()
{
    if (this->info) {
        delete[] this->info;
    }
}

template<typename TInfo>
void TDeque<TInfo>::Erase()
{
    while (this->front->next != nullptr) {
        this->front = this->front->next;
        delete this->front->prev;
    }
    delete this->front;
    this->front = nullptr;
    this->rear = nullptr;
    this->size = 0;
}

template<typename TInfo>
void TDeque<TInfo>::Clone(const TDeque& src)
{
    this->Erase();
    if (src->front == nullptr) {
        this->front = nullptr;
        this->rear = nullptr;
        size = 0;
    }
    for (size_t i = 0; i < src.size; ++i) {
        this->InsertRear(src.front->info);
        src.front = src.front->next;
    }
}

template<typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem* src)
{
    if (src == nullptr) {
        throw std::runtime_error("Invalid index");
    }
    if (src->next != nullptr) {
        src->next->prev = src->prev;
    }
    if (src->prev != nullptr) {
        src->prev->next = src->next;
    }
    --this->size;
    delete src;
}

template<typename TInfo>
typename TDeque<TInfo>::TDequeItem* TDeque<TInfo>::PtrByIndex(size_t index) const
{
    if (index >= size) {
        throw std::out_of_range("Wrong index");
    }
    TDequeItem* ptr = this->front;
    for (size_t i = 0; i < index; ++i) {
        ptr = ptr->next;
    }
    return ptr;
}

template<typename TInfo>
TDeque<TInfo>::TDeque() : front(nullptr), rear(nullptr), size(0)
{}

template <typename TInfo>
TDeque<TInfo>::TDeque(const TDeque& src)
{
    this->Clone(src);
}

template<typename TInfo>
TDeque<TInfo>::~TDeque()
{
    this->Erase();
}

template<typename TInfo>
void TDeque<TInfo>::InsertFront(const TInfo& data)
{
    if (this->front == nullptr) {
        this->front = new TDequeItem;
        this->front->next = nullptr;
        this->front->prev = nullptr;
        this->rear = this->front;
        this->front->info = data;
        ++this->size;
    }
    else {
        this->front->prev = new TDequeItem;
        this->front->prev->info = data;
        this->front->prev->next = this->front;
        this->front = this->front->prev;
        ++this->size;
    }
}

template <typename TInfo>
void TDeque<TInfo>::InsertRear(const TInfo& data)
{
    if (this->rear == nullptr) {
        InsertFront(data);
    }
    else { 
        this->rear->next = new TDequeItem;
        this->rear->next->info = data;
        this->rear->next->prev = this->rear;
        this->rear = this->rear->next;
        ++this->size;
    }
}

template <typename TInfo>
bool TDeque<TInfo>::DeleteFront()
{
    if (this->front == nullptr) {
        return false;
    }

    this->front = this->front->next;
    this->DeleteItem(this->front->prev);
    return true;
}

template <typename TInfo>
bool TDeque<TInfo>::DeleteRear()
{
    if (this->rear == nullptr) {
        return false;
    }

    this->rear = this->rear->prev;
    this->DeleteItem(this->rear->next);
    return true;
}

template <typename TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque& src)
{
    if (this == &src) {
        return *this;
    }
    this->Clone(src);
    return *this;
}

template <typename TInfo>
const TInfo& TDeque<TInfo>::GetInfoByIndex(size_t index) const
{
    return this->PtrByIndex(index)->info;
}

template <typename TInfo>
void TDeque<TInfo>::SetInfoByIndex(TInfo data, size_t index)
{
    this->PtrByIndex(index)->info = data;
}

template <typename TInfo>
void TDeque<TInfo>::BrowseNChange(void view(TInfo))
{
    for (size_t i = 0; i < this->size; ++i) {
        SetInfoByIndex((rand() % 10), i);
    }
    this->BrowseDnChange(view);
}

template <typename TInfo>
void TDeque<TInfo>::BrowseDnChange(void view(TInfo)) const
{
    TDequeItem* current = this->front;
    while (current != nullptr) {
        view(current->info);
        current = current->next;   
    }
}
