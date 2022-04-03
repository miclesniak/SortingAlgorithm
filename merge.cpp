//
// Created by Michał on 01.04.2022.
//

#include "merge.h"
#include <iostream>


using namespace std;

template<typename T>
void saveToTabForGrowing(T tmp_tab[], T tab[], int middle, int last, int &i, int &j, int &k) {
    while (i <= middle && j <= last) {
        if (tab[j] < tab[i]) {
            tmp_tab[k] = tab[j];
            j++;
        }
        else {
            tmp_tab[k] = tab[i];
            i++;
        }
        k++;
    }
}
template void saveToTabForGrowing<double>(double[], double[], int, int, int&, int&, int&);
template void saveToTabForGrowing<int>(int[], int[], int, int, int&, int&, int&);

template<typename T>
void saveToTabForDecresing(T tmp_tab[], T tab[], int middle, int last, int &i, int &j, int &k) {
    while (i <= middle && j <= last) {
        if (tab[j] > tab[i]) {
            tmp_tab[k] = tab[j];
            j++;
        } else {
            tmp_tab[k] = tab[i];
            i++;
        }
        k++;
    }
}
template void saveToTabForDecresing<double>(double[], double[], int, int, int&, int&, int&);

template<typename T>
void merge(T tab[], int start, int middle, int last, int x) {
    T *tmp_tab = new T[(last - start + 1)];
    int i{start};
    int j{middle + 1};
    int k{0};
    switch (x) {
        case 1:
        case 2:
        case 4:
            saveToTabForGrowing(tmp_tab, tab, middle, last, i, j, k);
            break;
        case 3:
            saveToTabForDecresing(tmp_tab, tab, middle, last, i, j, k);
            break;
        default:
            break;
    }
    if (i <= middle) {
        while (i <= middle) {
            tmp_tab[k] = tab[i];
            ++i;
            ++k;
        }
    } else {
        while (j <= last) {
            tmp_tab[k] = tab[j];
            ++j;
            ++k;
        }
    }

    for (int i{0}; i <= last - start; ++i) {
        tab[start + i] = tmp_tab[i];
    }
    delete[] tmp_tab;
}
template void merge<double>(double[], int, int , int , int);

template<typename T>
void merge_sort(T tab[], int start, int last, int x) {

    if (start != last) {
        int middle = (start + last) / 2;
        merge_sort(tab, start, middle, x);
        merge_sort(tab, middle + 1, last, x);
        merge(tab, start, middle, last, x);
    }

}
template void merge_sort<double>(double[], int, int, int);
