#include <iostream>
#include <list>

using namespace std;

int main() {
    int arrayLength;
    cin >> arrayLength;
    int heights[arrayLength];
    int nights[arrayLength] = {0};
    list<int> peaks;

    for (int i = 0; i < arrayLength; i++) {
        cin >> heights[i];
    }

    if (heights[0] >= heights[1]) {
        peaks.push_front(0);
    }

    int startIndex = (heights[0] >= heights[1]) ? 1 : 0;
    for (int i = startIndex; i < arrayLength - 1; i++) {
        if (heights[i] > heights[i - 1] && heights[i] >= heights[i + 1]) {
            peaks.push_front(i);
            break;
        }
    }

    int rising = 1;
    for (int i = startIndex + 1; i < arrayLength; i++) {
        if (heights[i] > heights[i - 1]) {
            rising++;
            if (heights[i] > heights[peaks.front()]) {
                nights[i] = max(nights[peaks.front()] + 1, rising);
                while (!peaks.empty() && heights[i] > heights[peaks.front()]) {
                    nights[i] = max(nights[i], nights[peaks.front()] + 1);
                    peaks.pop_front();
                }
                if (peaks.empty()) nights[i] = 0;
            } else {
                nights[i] = rising;
            }
            peaks.push_front(i);
        } else {
            nights[i] = 1;
            rising = 1;
        }
    }

    int maxNights = *max_element(nights, nights + arrayLength);
    cout << maxNights << endl;
    return 0;
}