//
// Created by Joseph Garcia on 2/27/24.
//

#ifndef CS8_VECTOR_SCRATCH_MYVECTOR_H
#define CS8_VECTOR_SCRATCH_MYVECTOR_H
#include <iostream>
template <typename T>
class myVector {

public:
    unsigned int size() const;
    T* begin() const;
    T& front() const;
    T& back()const;
    T& at(unsigned int index) const;
    T* end() const;
    bool empty() const;
    void push_back();
    void pop_back();
    void resize();

    myVector();
    myVector(unsigned int size);
    myVector(unsigned int size, T data);
    myVector<T>& operator+(const T& data);
    myVector<T>& operator-(const T& data);
    //myVector<T>& operator+(const T& data);
    //template<typename S> /// ?
    //LinkedList<T>& operator=(const myVector<T>& vector)
    //LinkedList<T>& operator=(const myVector<T>& vector); /// ?
    //LinkedList(const LinkedList<T>& list);
    ~myVector(); //Destructor

private:
    unsigned int capacity, sizeOfArray;
    T  array[];

};


#endif //CS8_VECTOR_SCRATCH_MYVECTOR_H
