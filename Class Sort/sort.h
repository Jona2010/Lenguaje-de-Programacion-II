#ifndef SORT_H
#define SORT_H
#include <iostream>

template<class T>
class Sort{
private:

public:
    virtual void sort_(T * &A, int n)=0;
    virtual ~Sort(){}
};

template<class T>
class Bubble:public Sort<T>{
private:
public:
    void sort_(T *& A, int n);
    ~Bubble(){
    }
};

template<class T>
class Selection:public Sort<T>{
private:
public:
    void sort_(T * &A, int n);
    ~Selection(){
    }
};

template<class T>
class Insertion:public Sort<T>{
private:
public:
    void sort_(T * &A, int n);
    ~Insertion(){
    }
};

template<class T>
class Merge:public Sort<T>{
private:

public:
    void sort_(T * &A, int n);
    void merge_sort(T * &A,int i,int j);
    void merge(T *&A,int i,int m,int j);
    ~Merge(){
    }
};

#include "sort.inl"
#endif
