#include <iostream>
#include <map>

using namespace std;

int main() {
    long long numRows, numQueries;
    cin >> numRows >> numQueries;

    map<long long, pair<long long, char>> windows;

    for (long long i = 0; i < numQueries; i++) {
        long long column, row;
        char direction;
        cin >> column >> row >> direction;

        auto it = windows.lower_bound(column);
        long long distance;

        if (it == windows.end()) {
            distance = (direction == 'U') ? numRows - column + 1 : column;
        } else if (it->first == column) {
            distance = 0;
        } else {
            if (direction == 'U') {
                if (it->first <= column) {
                    distance = numRows - column + 1;
                } else {
                    char upperBoundDirection = it->second.second;
                    distance = it->first - column;
                    if (upperBoundDirection == 'U') distance += it->second.first;
                }
            } else {
                if (it != windows.begin()) it--;
                if (it->first >= column) {
                    distance = column;
                } else {
                    char lowerBoundDirection = it->second.second;
                    distance = column - it->first;
                    if (lowerBoundDirection == 'L') distance += it->second.first;
                }
            }
        }

        windows[column] = {distance, direction};
        cout << distance << endl;
    }

    return 0;
}