#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long int n;
    long long int max;
    long long int m = 0;
    long long int Shomarandeh = 0;
    scanf("%lld %lld", &n, &max);
    long long int numbers[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld ", &m);
        numbers[i] = m;
    }
    long long int i = 0;
    long long int j = 0;
    long long int sum;
    long long int g = 0;
    sum += numbers[i];
    for (i = 0; i < n; i++){
        sum = 0;
        for (j = i + 1; j <= n; j++){
        sum = sum + numbers[j - 1];
        //g+= 2;
        if (sum <= max) {
                g+= 1;
            }
        }
    }
    printf("%lld ", g);
}
