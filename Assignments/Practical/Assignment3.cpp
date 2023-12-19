#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long num;
    long long tool;
    long long radif;
    long long sotoon;
    long long num2;
    char direction;
    char direction_of_upper_bound;

    map<long long, pair<long long,char>> window;
    map<long long, pair<long long,char>> :: iterator itr;

    cin >> tool;
    cin >> num;

    for (long long i = 0; i < num; i++) {
        cin >> sotoon;
        cin >> radif;
        cin >> direction;
        itr = window.lower_bound(sotoon);
        if (itr -> first == 0) {
            if (direction == 'U') num2 = tool - sotoon + 1;
            else num2 = sotoon;
        } else if (itr -> first == sotoon) {
            num2 = 0;
            cout << num2 << endl;
            continue;
        } else if (direction == 'U') {
            if (itr -> first <= sotoon) {
                num2 = tool - sotoon + 1;
            } else {
                direction_of_upper_bound = (itr -> second).second;
                num2 = itr -> first - sotoon;
                if (direction_of_upper_bound == 'U') num2 += (itr -> second).first;
            }
        } else {
            if (itr != window.begin()) itr--;
            if (itr -> first >= sotoon) {
                num2 = sotoon;
            } else {
                direction_of_upper_bound = (itr -> second).second;
                num2 = sotoon - itr -> first;
                if (direction_of_upper_bound == 'L') num2 += (itr -> second).first;
            }
        }
        window.insert({sotoon, {num2, direction}});
        cout << num2 << endl;
    }
}
