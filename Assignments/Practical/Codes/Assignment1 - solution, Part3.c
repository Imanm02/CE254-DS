#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n, maxSum;
    scanf("%lld %lld", &n, &maxSum);
    long long numbers[n], sum = 0, subarrayCount = 0;

    // خواندن اعداد
    for (long long i = 0; i < n; i++) {
        scanf("%lld ", &numbers[i]);
    }

    for (long long start = 0, end = 0; start < n; start++) {
        // اضافه کردن عناصر تا زمانی که مجموع کمتر یا مساوی maxSum باشد
        while (end < n && sum + numbers[end] <= maxSum) {
            sum += numbers[end++];
        }

        // اضافه کردن تعداد زیرآرایه‌های ممکن با شروع از عنصر فعلی
        subarrayCount += end - start;

        // کاستن عنصر شروع از مجموع
        sum -= numbers[start];
    }

    printf("%lld ", subarrayCount);
    return 0;
}