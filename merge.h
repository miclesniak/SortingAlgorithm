//
// Created by Michał on 01.04.2022.
//

#ifndef SORTING_MERGE_H
#define SORTING_MERGE_H
template<typename T>
void saveToTabForGrowing(T tmp_tab[], T tab[], int middle, int last, int &i, int &j, int &k);

template<typename T>
void saveToTabForDecresing(T tmp_tab[], T tab[], int middle, int last, int &i, int &j, int &k);


template<typename T>
void merge(T tab[], int start, int middle, int last, int x);

template<typename T>
void merge_sort(T tab[], int start, int last, int x);
#endif //SORTING_MERGE_H
