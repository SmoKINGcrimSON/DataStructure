#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>

template<typename V>
void QuickSort(V*, int, int);

template<typename V>
void Swap(V*, int, int);

#include "quicksort.tpp"
#endif