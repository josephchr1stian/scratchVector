//
// Created by Joseph Garcia on 2/27/24.
//

#ifndef CS8_VECTOR_SCRATCH_MYVECTOR_H
#define CS8_VECTOR_SCRATCH_MYVECTOR_H
#include <iostream>
#include <algorithm>
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
    void push_back(const T& data);
    void pop_back();
    void sort(unsigned int start, unsigned int end);
    unsigned int divide(unsigned int start, unsigned int end);
    myVector();
    myVector(unsigned int size, T& data);
    explicit myVector(unsigned int size);
    myVector<T>& operator+(const T& data);
    myVector<T>& operator+(const myVector<T> & vector);
    myVector<T>& operator-(const T& data);
    myVector<T>& operator-(const myVector<T> & vector);
    myVector<T>& operator=(const myVector<T>& data);
    bool operator==(const myVector<T>& vector);
    friend std::ostream& operator<<(std::ostream& out, const myVector<T>& vector);
    ~myVector(); //Destructor
    //myVector<T>& operator+(const T& data);
    //template<typename S> /// ?
    //LinkedList<T>& operator=(const myVector<T>& vector)
    //LinkedList<T>& operator=(const myVector<T>& vector); /// ?
    //LinkedList(const LinkedList<T>& list);


private:
    unsigned int capacity, sizeOfArray;
    void resize();
    void resizeDown();
    T  array[];

};


#endif //CS8_VECTOR_SCRATCH_MYVECTOR_H
