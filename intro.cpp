//
// Created by Michał on 01.04.2022.
//
#include<iostream>
#include<random>
#include<ctime>
#include<cmath>

template <typename T>
void InsertionSort(T tab[], int size,int x) {
    int j{};
    for(int i{1}; i < size; ++i) {
        int tmp = tab[i];
        switch (x) {
            case 1:
            case 2:
            case 4:
                for (j = i; j > 0 && tmp < tab[j - 1]; --j) {
                    tab[j] = tab[j - 1];
                }
                tab[j] = tmp;
                break;
            case 3:
                for (j = i; j > 0 && tmp > tab[j - 1]; --j) {
                    tab[j] = tab[j - 1];
                }
                tab[j] = tmp;

        }
    }
}

template void InsertionSort<double>(double[], int ,int);

template <typename T>
void heapify(T tab[], int size, int i , int x)
{
    int largest = i;
    int left = 2 * i + 1; // lewy = 2*i + 1
    int right = 2 * i + 2; // prawy = 2*i + 2
    T tmp = 0;
    switch (x) {
        case 1:
        case 2:
        case 4:
            if (left < size && tab[left] > tab[largest]) { // zamienia największą liczbę na wartość lewą, jeśli jest spełniony warunek
                largest = left;
            }
            if (right < size && tab[right] > tab[largest]) { // zamienia największą liczbę na wartość prawą, jeśli jest spełniony warunek
                largest = right;
            }
            break;
        case 3:
            if (left < size && tab[left] < tab[largest]) { // zamienia (tutaj najniższą) liczbę na wartość lewą, jeśli jest spełniony warunek
                largest = left;
            }
            if (right < size && tab[right] < tab[largest]) { // zamienia (tutaj najniższą) liczbę na wartość prawą, jeśli jest spełniony warunek
                largest = right;
            }
            break;
    }
    if (largest != i) { // jeśli największa/najniższa nie jest równa i zamienia miejscami
        tmp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = tmp;
        heapify(tab, size, largest, x); // rekurencyjnie wywołanie funkcji
    }

}
template void heapify<double>(double[], int, int, int);

template <typename T>
void heap_sort(T tab[], int size, int x) // funkcja heapsort
{
    T tmp = 0;
    for (int i = size / 2 - 1; i >= 0; i--) { // zamiana miejsc w tablicy
        heapify(tab, size, i, x);
    }
    for (int i = size - 1; i >= 0; i--) { //zamienia miejscami kolejne wartości
        tmp = tab[0];
        tab[0] = tab[i];
        tab[i] = tmp;
        heapify(tab, i, 0, x);
    }
}
template void heap_sort<double>(double[], int, int);

template<typename Type>
int division(Type tab[], int left, int right, int x) // funckja dzieląca tablicę na 2 części: na tablicę posiadającą mniejsze lub równe oraz na większe lub równe liczby od tmp1
{
    Type pivot = tab[(left + right) / 2]; // obieramy pivot
    Type tmp2 = 0; // do zamiany miejsc
    while (true) // petla nieskonczona, kończy się przy return
    {
        switch (x) {
            case 1:
            case 2:
            case 4:
                //sortowanie rosnace
                while (tab[right] > pivot) // dopoki elementy sa wieksze od pivot
                    --right;
                while (tab[left] < pivot) // dopoki elementy sa mniejsze od pivot
                    ++left;
                break;
            case 3: // sortowanie malejace
                while (tab[right] < pivot) // dopoki elementy sa mniejsze od pivot
                    --right;
                while (tab[left] > pivot) // dopoki elementy sa wieksze od pivot
                    ++left;
                break;
        }
        if (left < right) // zamieniamy miejscami gdy left < right
        {
            tmp2 = tab[left];
            tab[left] = tab[right];
            tab[right] = tmp2;
            left++;
            right--;
        }
        else { // zwracamy right jako punkt podzialu tablicy gdy left >= right
            return right;
        }
    }
}
template int division<double>(double[], int , int, int);

template <typename T>
void Mixed_sort(T tab[], int size, int depthLimit, int x)
{
    int pivot = 0;
    if(depthLimit <=0 ) {
        heap_sort(tab, size, x);
        return;
    }
    pivot = division(tab, 0, size - 1, x);
    if(pivot > 9) {
        Mixed_sort(tab, pivot, depthLimit - 1, x);
    }
    if(size - 1 - pivot > 9) {
        Mixed_sort(tab + pivot + 1, size - 1 - pivot, depthLimit - 1, x);
    }
}
template void Mixed_sort<double >(double [], int, int, int);

template <typename T>
void IntroSort (T tab[], int size, int x) // funkcja sortująca
{
    int depth_limit = floor(2 * log(size)/M_LN2);
    Mixed_sort(tab, size, depth_limit, x); //wywołanie funkcji Mixed_sort
    InsertionSort(tab, size, x);
}

template void IntroSort<double>(double[], int, int);