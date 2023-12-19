#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int n;
    long long int max;
    long long int Shomarandeh;
    scanf("%lld %lld", &n, &max);
    long long int m = 0;
    long long int numbers[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld ", &m);
        numbers[i] = m;
    }
    long long int k = 0;
    long long int j = 1;
    long long int sum = 0;
    sum += numbers[k];
    for ( k = 0; k < n; k++) {
        while (sum <= max && j <= n) {
            sum = sum + numbers[j];
            Shomarandeh = Shomarandeh + j - k;
            j++;
        }
        sum = sum - numbers[k];
    }
    printf("%lld ", Shomarandeh);
}
