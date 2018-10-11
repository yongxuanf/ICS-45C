#ifndef MAPARRAY_H
#define MAPARRAY_H
#include <iostream>
using namespace std;

template
    <typename T1,typename T2>
class MapArray
{
	int size;
	pair<T1, T2> * buf;
public:
	struct iterator
    {
        typedef forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef pair<T1, T2> value_type;
        typedef pair<T1, T2>& reference;
        typedef pair<T1, T2>* pointer;
    private:
        pointer ibuf;
    public:
        iterator(pointer ptr) : ibuf(ptr) { }
        self_type operator++() { ++ibuf; return *this; }
        self_type operator++(int postfix) { self_type cpy = *this; ++ibuf; return cpy; }
        self_type operator--() { --ibuf; return *this; }
        self_type operator--(int postfix) { self_type cpy = *this; --ibuf; return cpy; }
        self_type operator+=(int i) { ibuf+=i; return *this; }
        self_type operator+(int i) { ibuf+=i; return *this; }
        self_type operator-=(int i) { ibuf-=i; return *this; }
        self_type operator-(int i) { ibuf-=i; return *this; }
        reference operator*() { return *ibuf; }
        pointer operator->() { return ibuf; }
        bool operator==(const self_type& rhs) const { return ibuf == rhs.ibuf; }
        bool operator!=(const self_type& rhs) const { return ibuf != rhs.ibuf; }
        bool operator<(const self_type& rhs) const { return ibuf < rhs.ibuf; }
        bool operator>(const self_type& rhs) const { return ibuf > rhs.ibuf; }
        bool operator<=(const self_type& rhs) const { return ibuf <= rhs.ibuf; }
        bool operator>=(const self_type& rhs) const { return ibuf >= rhs.ibuf; }
        
    };

    MapArray():size(0),buf(new pair<T1,T2> [size]){}
    int find(T1 index)
    {
    	for(int i = 0; i< size ; ++i)
    	{
    		if(buf[i].first == index)
    		{
    			return i;
    		}
    	}
    	return -1;
    }
 pair<T1,T2>& insert ( pair<T1, T2> p)
        {
            pair<T1,T2> *temp = new pair<T1, T2>[++size];
            int count = size-1;
            for (int i = 0; i < count; i++)
            {
                if (p.first < buf[i].first)
                {
                    count = i;
                }
                else
                {
                    temp[i] = buf[i];
                }
            }
            temp[count] = p;
            for (int i = count+1; i < size; i++)
            {
                temp[i] = buf[i-1];
            }
            delete[]buf;
            buf = temp;
            return buf[count];
        }

    T2& operator[](const T1& k)
        {
            for (int i = 0; i<size; i++)
            {
                if(buf[i].first == k)
                {
                    return buf[i].second;
                }
            }
            return insert(make_pair(k, T2())).second;
        }
    iterator begin()
    {
    	return iterator(buf);
    }
    iterator end()
    {
    	return iterator(buf) + size;
    }
    ~MapArray()
    {
    	delete[] buf;
    }
};

#endif
