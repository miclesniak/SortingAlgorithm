#include <iostream>
#include <random>
#include <ctime>

#include "handling.h"
#include "intro.h"
#include "quick.h"
#include "merge.h"

using namespace std;


int main() {
    int size{};
    int x{};
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> distr(-100,100);
    cout << "Podaj rozmiar tablicy:  ";
    cin >> size;
    print_menu();
    cin >> x;
    auto *tab_quick = new double[size];
    auto *tab_merge = new double[size];
    auto *tab_intro = new double[size];

    while(x) {
        float time_quick = 0;
        float time_merge = 0;
        float time_intro = 0;
        switch (x) {
            case 0:
                cout<<"Koniec dzialania programu\n";
                break;
            case 1:
            case 3:
                for (int j{0}; j < 100; ++j) {
                    for (int i{0}; i < size; ++i) {
                        tab_quick[i] = distr(gen);
                        tab_merge[i] = distr(gen);
                        tab_intro[i] = distr(gen);
                    }
                    clock_t timeBegin_quick = clock();
                    quick_sort(tab_quick, 0, size - 1, x);
                    clock_t timeEnd_quick = clock();
                    time_quick += timeEnd_quick - timeBegin_quick;

                    clock_t timeBegin_merge = clock();
                    merge_sort(tab_merge, 0, size - 1, x);
                    clock_t timeEnd_merge = clock();
                    time_merge += timeEnd_merge - timeBegin_merge;

                    clock_t timeBegin_intro = clock();
                    IntroSort(tab_intro,size, x);
                    clock_t timeEnd_intro = clock();
                    time_intro += timeEnd_intro - timeBegin_intro;

                }
                check(tab_quick, size, x);
                check(tab_merge, size, x);
                check(tab_intro, size, x);

                cout << "Czas sortowania quicksort: " << (time_quick / CLOCKS_PER_SEC) << "s\n";
                cout << "Czas sortowania mergesort: " << (time_merge / CLOCKS_PER_SEC) << "s\n";
                cout << "Czas sortowania introsort: " << (time_intro / CLOCKS_PER_SEC) << "s\n";
                break;
            case 2:
                float percentage;
                cout << "Jaka czesc tablicy jest juz posortowana: \n";
                cin >> percentage;
                for (int j{0}; j < 100; ++j) {
                    for (int i{0}; i < size; ++i) {
                        tab_quick[i] = distr(gen);
                        tab_merge[i] = distr(gen);
                        tab_intro[i] = distr(gen);
                    }
                    quick_sort(tab_quick, 0, static_cast<int>(percentage / 100 * size), x);
                    merge_sort(tab_merge, 0, static_cast<int>(percentage / 100 * size), x);
                    IntroSort(tab_intro,static_cast<int>(percentage / 100 * size), x);

                    clock_t timeBegin_quick = clock();
                    quick_sort(tab_quick, 0, size - 1, x);
                    clock_t timeEnd_quick = clock();
                    time_quick += timeEnd_quick - timeBegin_quick;

                    clock_t timeBegin_merge = clock();
                    merge_sort(tab_merge, 0, size - 1, x);
                    clock_t timeEnd_merge = clock();
                    time_merge += timeEnd_merge - timeBegin_merge;

                    clock_t timeBegin_intro = clock();
                    IntroSort(tab_intro,size, x);
                    clock_t timeEnd_intro = clock();
                    time_intro += timeEnd_intro - timeBegin_intro;



                }
                check(tab_quick, size, x);
                check(tab_merge, size, x);
                check(tab_intro, size, x);

                cout << "Czas sortowania quicksort: " << (time_quick / CLOCKS_PER_SEC) << "s\n";
                cout << "Czas sortowania mergesort: " << (time_merge / CLOCKS_PER_SEC) << "s\n";
                cout << "Czas sortowania introsort: " << (time_intro / CLOCKS_PER_SEC) << "s\n";
                break;
            case 4:
                for (int j{0}; j < 100; ++j) {
                    for (int i{0}; i < size; ++i) // wczytywanie losowych liczb do tablicy
                    {
                        tab_quick[i] = distr(gen);
                    }
                    quick_sort(tab_quick, 0, size - 1, 3);
                    merge_sort(tab_merge, 0, size - 1, 3);
                    IntroSort(tab_intro, size, 3);

                    clock_t timeBegin_quick = clock();
                    quick_sort(tab_quick, 0, size - 1, x);
                    clock_t timeEnd_quick = clock();
                    time_quick += timeEnd_quick - timeBegin_quick;

                    clock_t timeBegin_merge = clock();
                    merge_sort(tab_merge, 0, size - 1, x);
                    clock_t timeEnd_merge = clock();
                    time_merge += timeEnd_merge - timeBegin_merge;

                    clock_t timeBegin_intro = clock();
                    IntroSort(tab_intro,size, x);
                    clock_t timeEnd_intro = clock();
                    time_intro += timeEnd_intro - timeBegin_intro;
                }
                check(tab_quick, size, x);
                check(tab_merge, size, x);
                check(tab_intro, size, x);

                cout << "Czas sortowania quicksort: " << (time_quick / CLOCKS_PER_SEC) << "s\n";
                cout << "Czas sortowania mergesort: " << (time_merge / CLOCKS_PER_SEC) << "s\n";
                cout << "Czas sortowania introsort: " << (time_intro / CLOCKS_PER_SEC) << "s\n";
                break;
            default:
                cout << "Nie ma takiej opcji" << endl;
                break;
        }
        print_menu();
        cin>>x;
    }

    delete[] tab_quick;
    delete[] tab_merge;
    delete[] tab_intro;// usunięcie tablicy, aby nie było wycieku
    return 0;
}
