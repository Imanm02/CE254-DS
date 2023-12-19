#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n, maxSum, currentNumber, subarrayCount = 0;
    scanf("%lld %lld", &n, &maxSum);
    long long numbers[n];

    // خواندن اعداد
    for (long long i = 0; i < n; i++) {
        scanf("%lld ", &currentNumber);
        numbers[i] = currentNumber;
    }

    // محاسبه تعداد زیرآرایه‌ها
    for (long long i = 0; i < n; i++) {
        long long sum = 0;
        for (long long j = i; j < n; j++) {
            sum += numbers[j];
            if (sum <= maxSum) {
                subarrayCount++;
            }
        }
    }

    printf("%lld ", subarrayCount);
    return 0;
}