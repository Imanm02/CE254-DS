#include <iostream>
#include <string>
using namespace std;

long long computeMaxSymmetricParts(string str) {
    long long phase = 1, power = 1, prime = 31;
    long long halfSize = str.size() / 2;
    long long firstHash = 0, secondHash = 0, modulo = 1e9 + 7;

    for (long long i = 0; i < halfSize; ++i) {
        char firstChar = str[i];
        char secondChar = str[str.size() - 1 - i];
        firstHash = ((firstHash * prime) + (firstChar - 'a' + 1)) % modulo;
        secondHash = (secondHash + power * (secondChar - 'a' + 1)) % modulo;
        power = (power * prime) % modulo;

        if (firstHash == secondHash) {
            firstHash = 0, secondHash = 0, power = 1;
            phase += 2;
            if (i == str.size() - i - 2)
                phase--;
        }
    }
    return phase;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; ++i) {
        string str;
        cin >> str;
        cout << computeMaxSymmetricParts(str) << endl;
    }
    return 0;
}