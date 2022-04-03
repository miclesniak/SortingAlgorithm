//
// Created by Michał on 01.04.2022.
//

#include "quick.h"

template<typename T>

int division(T tab[], int left, int right, int x) {
    T pivot = tab[(left + right) / 2];
    T tmp{0};
    while (true) {
        switch (x) {
            case 1:
            case 2:
            case 4:
                while (tab[right] > pivot)
                    --right;
                while (tab[left] < pivot)
                    ++left;
                break;
            case 3:
                while (tab[right] < pivot)
                    --right;
                while (tab[left] > pivot)
                    ++left;

                break;
        }
        if (left < right) {
            tmp = tab[left];
            tab[left] = tab[right];
            tab[right] = tmp;
            ++left;
            --right;
        } else
            return right;
    }
}
template int division<int>(int[], int, int, int);
template int division<double>(double[], int, int, int);

template<typename T>
void quick_sort(T tab[], int left, int right, int x) {
    T pivot{0};
    if (left < right) {
        pivot = division(tab, left, right, x);
        quick_sort(tab, left, pivot, x);
        quick_sort(tab, pivot + 1, right, x);
    }
}

template void quick_sort<int>(int[], int , int , int);
template void quick_sort<double>(double[], int , int , int);