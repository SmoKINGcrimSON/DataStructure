#ifndef SORTS_H
#define SORTS_H
#include <iostream>

namespace sorts{
    //merged sort
    template<typename V>
    void MergedSort(V*, const int);
    template<typename V>
    void Merge(V*, const int, V*, const int, V*, const int);
    //quick sort
    template<typename V>
    void QuickSort(V*, int, int);
    template<typename V>
    int Partition(V*, int, int);
}

#include "sorts.tpp"
#endif