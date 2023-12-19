#include <iostream>
#include <list>

using namespace std;

int main() {
    int array_lengh;
    cin >> array_lengh;
    int array[ array_lengh ];
    int nights[ array_lengh ];
    list <int> peaks;
    for (int i = 0; i < array_lengh; i++) {
        cin >> array[ i ];
        nights[ i ] = 0;
    }
    int j = 0;
    if (array[ 0 ] >= array[ 1 ]) {
        peaks.push_front(0);
    } else {
        for (j = 1; j < array_lengh - 1; j++) {
            if (array[ j - 1 ] < array[ j ] && array[ j ] >= array[ j + 1 ]) {
                peaks.push_front(j);
                break;
            }
        }
    }
    int rising = 1;
    for (int i = j + 1; i < array_lengh; i++) {
        if (array[ i - 1 ] < array[ i ]) {
            rising++;
            if (array[ peaks.front() ] < array[ i ]) {
                if (rising > nights[ peaks.front() ]) nights[ i ] += rising;
                else nights[ i ] += nights[ peaks.front() ] + 1;
                while (peaks.size() > 0) {
                    if (array[ i ] > array[ peaks.front() ]) {
                        if (nights[ peaks.front() ] + 1 > nights[ i ]) nights[ i ] = nights[ peaks.front() ] + 1;
                        peaks.pop_front();
                    }
                    else break;
                }
                if (peaks.size() == 0) nights[ i ] = 0;
            } else {
                nights[ i ] += rising;
            }
            peaks.push_front(i);
        } else {
            nights[ i ] = 1;
            rising = 1;
        }
    }
    int max_of_nights = 0;
    for (int i = 0; i < array_lengh; i++) {
        if (nights[ i ] > max_of_nights) max_of_nights = nights[ i ];
    }
    cout << max_of_nights << endl;
}