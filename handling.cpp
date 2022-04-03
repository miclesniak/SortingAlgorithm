//
// Created by Michał on 01.04.2022.
//

#include "handling.h"
using namespace std;

void print_menu(){
    cout << "Wybierz opcje:\n";
    cout << "1 - Posortuj rosnaco losowe liczby.\n";
    cout << "2 - Posortuj, gdzie dana czesc liczb jest posortowana. \n";
    cout << "3 - Posortuj malejaco losowe liczby. \n" ;
    cout << "4 - Posortuj rosnaco, liczby posortowane malejaco. \n";
    cout << "0 - Zakoncz dzialanie programu. \n";
    cout << "Twoj wybor: \n";
}

//template<typename T>
//void check(T tab[], int size, int x) {
//    for (int i{0}; i <= size - 2; ++i) {
//        switch (x) {
//            case 1:
//            case 2:
//            case 4:
//                if (!(tab[i + 1] >= tab[i]))
//                    cout << "Posortowano niepoprawnie\n";
//                break;
//            case 3:
//                if (!(tab[i + 1] <= tab[i]))
//                    cout << "Posortowano niepoprawnie\n";
//                break;
//        }
//    }
//}

template<typename T>
void check(T tab[], int size, int x) {
    bool is_correct{1};
    for (int i{0}; i <= size - 2; ++i) {
        switch (x) {
            case 1:
            case 2:
            case 4:
                if (tab[i + 1] >= tab[i]);
                else
                    is_correct = false;
                break;
            case 3:
                if (tab[i + 1] <= tab[i]);
                else
                    is_correct = false;
                break;
        }
    }
    if (is_correct)
        cout << "Posortowano poprawnie\n";
    else
        cout << "Posortowano niepoprawnie\n";
}

template void check<double>(double[], int, int);
