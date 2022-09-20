#ifndef SORTS_H
#define SORTS_H
#include <iostream>

namespace sorts{
    template<typename V>
    int BynarySearch(const V*, V, const int);

    template<typename V>
    void MergedSort(V*, const int);
    template<typename V>
    void Merge(V*, const int, V*, const int, V*, const int);
}

#include "sorts.tpp"
#endif