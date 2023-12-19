#include <iostream>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

long long int solve(string Reshteh)
{
    long long int marhaleh = 1, tavan = 1, p = 31;
    long long int size = Reshteh.size() / 2;
    long long int firstHash = 0;
    long long int secondHash = 0;
    long long int m = 1e9 + 7;
    for (long long int i = 0; i < size; ++i)
    {
        int fir = i;
        char first = Reshteh[fir];
        int sec = Reshteh.size() - 1 - i;
        char second = Reshteh[sec];
        firstHash = ((firstHash * p) + (first - 'a' + 1));
        firstHash %= m;
        secondHash = (secondHash + tavan * (second - 'a' + 1));
        secondHash %= m;
        tavan = (tavan * p);
        tavan = tavan % m;
        if (firstHash == secondHash)
        {
            firstHash = 0 , secondHash = 0, tavan = 1;
            marhaleh = marhaleh + 2;
            int partSecond = Reshteh.size() - i - 2;
            if (i == Reshteh.size() - i - 2)
                marhaleh--;
        }
    }
    return marhaleh;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n+1; i++)
    {
        string toSolve;
        cin >> toSolve;
        cout << solve(toSolve) << endl;
    }
    return 0;
}