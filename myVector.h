//
// Created by Joseph Garcia on 2/27/24.
//
#ifndef CS8_VECTOR_SCRATCH_MYVECTOR_H
#define CS8_VECTOR_SCRATCH_MYVECTOR_H

#include "vex.h"
#include "vit.h"

template <typename T>
class myVector {
public:
    unsigned int size() const;
    /* small methods should be made inline */ 
    /* 
     * compile doesn't inline if not defined in class 
     * declaration 
     */
    inline VecIterator<T> begin() const noexcept(false);
    inline T& front() const noexcept(false);
    inline T& back()const noexcept(false);
    inline T& at(unsigned int index) const noexcept(false);
    inline T& operator[](unsigned int) const;
    inline VecIterator<T> end() const noexcept(false);

    inline bool empty() const;
    void push_back(T);
    void pop_back() noexcept(false);
    void resize();

    template <typename U> 
    friend std::ostream& operator<<(const std::ostream& os, const myVector<U>& v);

    myVector();
    myVector(unsigned int size);
    myVector(unsigned int size, T data);
    /* don't know how subtracting vectors /should/ work */
    ~myVector(); //Destructor

private:
    unsigned int capacity, sizeOfArray;
    /* use pointers for heap */
    T*  array;
};


template <typename T>
myVector<T>::myVector()
{
    capacity = 0;
    sizeOfArray = 0;
    array = nullptr;

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

    for (int i = 0; i < sizeOfArray; ++i)
        array[i] = data;
}

template <typename T>
inline VecIterator<T> myVector<T>::begin() const noexcept(false)
{
    if (!capacity) 
        throw VecEmpty(); 
    /* base of the array is the zeroth element */ 
    return VecIterator<T>(&array[0]);
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
    if (index < 0) 
        throw VecEmpty();
    /* do not allow users to read into garbage 
     * capacity
     */
    else if (index > sizeOfArray-1)
        throw VecOOB();
    return array[index];
}

template <typename T> 
inline T& myVector<T>::operator[](unsigned int index) const {
    /* don't throw errors */
    return array[index];
}


template <typename T>
inline VecIterator<T> myVector<T>::end() const noexcept(false) {
    if (!capacity) 
        throw VecEmpty();
    /* read past the last element */ 
    return VecIterator<T>(&array[sizeOfArray]);
}

template <typename T> 
bool myVector<T>::empty() const {
    return !sizeOfArray ? true : false; 
}

template<typename T>
void myVector<T>::push_back(T element) {
    if (sizeOfArray + 1 > capacity)  
        this->resize(); 
    
    array[sizeOfArray] = element;
    ++sizeOfArray;

    return;
}

template<typename T>
void myVector<T>::pop_back() {
    if (capacity == 0) 
        throw VecEmpty();
    /* do not waste time writing to memory */
    /* just mark it as deallocated */
    sizeOfArray--;
    
    return;
}

template<typename T>
void myVector<T>::resize()
{
    T _array[sizeOfArray];
    for (int i = 0; i < sizeOfArray; ++i)
        _array[i] = array[i];

    if (array != nullptr) 
        delete[] array;

    capacity = (capacity == 0 ? 1 : capacity * 2); 

    array = new T[capacity];

    for (int i = 0; i < sizeOfArray; ++i) 
        array[i] = _array[i];

    return;
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


template <typename T>
std::ostream& operator<<(std::ostream& os, const myVector<T>& v) {
    for (int i = 0; i < v.size(); ++i) 
        os << v[i] << ' ';
    return os;
}

#endif //CS8_VECTOR_SCRATCH_MYVECTOR_H
