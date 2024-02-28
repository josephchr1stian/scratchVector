//
// Created by Joseph Garcia on 2/27/24.
//
#ifndef CS8_VECTOR_SCRATCH_MYVECTOR_H
#define CS8_VECTOR_SCRATCH_MYVECTOR_H
#include <iostream>

#include "vex.h"

template <typename T>
class myVector {
public:
    unsigned int size() const;
    /* small methods should be made inline */ 
    /* 
     * compile doesn't inline if not defined in class 
     * declaration 
     */
    inline T* begin() const noexcept(false);
    inline T& front() const noexcept(false);
    inline T& back()const noexcept(false);
    inline T& at(unsigned int index) const noexcept(false);
    inline T* end() const noexcept(false);

    inline bool empty() const;
    void push_back(T);
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
    /* use pointers for heap arrays */
    T*  array;
};


template <typename T>
myVector<T>::myVector()
{
    capacity = 0;
    sizeOfArray = 0;

    return; 
}

template <typename T>
myVector<T>::myVector(unsigned int size)
{

     array = new T[size];
     capacity = size;
     sizeOfArray = size;

}
template <typename T>
myVector<T>::myVector(unsigned int size, T data)
{
    array = new T[size];
    sizeOfArray = size;
    capacity = size;

    for (int i = 0; i < size; i++)
    {
        array[i] = data;
    }


}

template <typename T>
inline T* myVector<T>::begin() const noexcept(false)
{
    if (!capacity) 
        throw VecEmpty(); 
    /* base of the array is the zeroth element */ 
    return &array;
}

template <typename T>
inline T& myVector<T>::front() const noexcept(false)
{
    if (sizeOfArray == 0)
        throw VecEmpty();
    return *array;
}

template <typename T>
inline T& myVector<T>::back() const noexcept(false)
{
    if (sizeOfArray == 0) 
        throw VecEmpty();
    return array[sizeOfArray-1];
}

template <typename T>
inline T& myVector<T>::at(unsigned int index) const noexcept(false) {
    if (index > sizeOfArray || index < 0) 
        throw VecEmpty();
    return array[index];
}

template <typename T>
inline T* myVector<T>::end() const noexcept(false) {
    if (!capacity) 
        throw VecEmpty();
    return &array[size-1];
}

template <typename T> 
bool myVector<T>::empty() const {
    return !sizeOfArray ? true : false; 
}

template<typename T>
void myVector<T>::push_back(T element) {
    if (capacity == sizeOfArray)  
        this->resize(); 
    
    array[sizeOfArray-1] = element;
    sizeOfArray++;

    return;
}

template<typename T>
void myVector<T>::pop_back() {
    /* do not waste time writing to memory */
    /* just mark it as deallocated */
    sizeOfArray--;
    
    return;
}

template<typename T>
void myVector<T>::resize()
{
    if (sizeOfArray == 0)
        sizeOfArray = capacity = 1; 

    capacity *= 2;
    T *arrayCopy = new T[capacity];

    for( int i = 0; i < sizeOfArray-1; i++)
        arrayCopy[i] = array[i]; 

    delete array;
    array = arrayCopy;
}


template <typename T>
inline unsigned int myVector<T>:: size() const
{
    return sizeOfArray;
}


template <typename T>
myVector<T>::~myVector() {
    delete[] array;

    return;
}

#endif //CS8_VECTOR_SCRATCH_MYVECTOR_H
