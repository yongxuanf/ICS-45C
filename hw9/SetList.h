#ifndef SETLIST_H
#define SETLIST_H
#include <iostream>
using namespace std;

template <typename Type>
 struct ListNode
    {
        Type info;
        ListNode<Type> * next;
        ListNode(Type newInfo, ListNode<Type> * newNext = nullptr): info( newInfo ), next( newNext ){}
        static void deleteList(ListNode<Type> * L)
            {
                if ( L )
                {
                    deleteList( L->next );
                    delete L;
                }
            }
    };
template <typename T>
class SetList
{
    ListNode<T>* head;

public:
    struct iterator
    {
        typedef std::forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef ListNode<T> value_type;
        typedef ListNode<T>& reference;
        typedef ListNode<T>* pointer;
    private:
        pointer ibuf;
    public:
        iterator(pointer ptr) : ibuf(ptr) { }
        self_type operator++() { ibuf = ibuf->next; return *this; }
        self_type operator++(int postfix) { self_type cpy = *this; ibuf = ibuf->next; return cpy; }
        reference operator*() { return ibuf->info; }
        pointer operator->() { return ibuf; }
        bool operator==(const self_type& rhs) const { return ibuf == rhs.ibuf; }
        bool operator!=(const self_type& rhs) const { return ibuf != rhs.ibuf; }
    };
    SetList():head(nullptr){}
    void insert(T i)
        {
            head = new ListNode<T>(i, head);
        }

    iterator begin()
        {
            return iterator(head);

        }
    iterator end()

        {
            return iterator(nullptr);
        }

    iterator find(const T& i)
        {
            for (ListNode<T> * p = head; p; p = p->next)
            {
                if (p->info == i)
                    return iterator(p);
            }
            return iterator(nullptr);
        }
    ~SetList()
        {
            ListNode<T>::deleteList(head);

        }

};

#endif
