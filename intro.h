//
// Created by Michał on 01.04.2022.
//

#ifndef SORTING_INTRO_H
#define SORTING_INTRO_H
template <typename T>
void InsertionSort(T tab[], int size,int x);

template <typename T>
void heapify(T tab[], int size, int i , int x);

template <typename T>
void heap_sort(T tab[], int size, int x);

template<typename Type>
int division(Type tab[], int left, int right, int x);

template <typename T>
void Mixed_sort(T tab[], int size, int depthLimit, int x);

template <typename T>
void IntroSort (T tab[], int size, int x);

#endif //SORTING_INTRO_H
