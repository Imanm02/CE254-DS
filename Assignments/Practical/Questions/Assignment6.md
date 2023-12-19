+ محدودیت زمان: ۱ ثانیه
+ محدودیت حافظه: ۲۵۶ مگابایت

----------

استاد شیفو می‌خواهد طومار اژدها را تا زمانی که پو آماده‌ی پذیرش جنگجویی اژدها شود، در مکانی امن نگه دارد تا به دست کسی نیفتد و برای همین طومار را داخل یک گاو صندوق پیشرفته می‌گذارد. حال که پو به آمادگی لازم رسیده است، استاد می‌خواهد طومار را به او بدهد اما کهولت سن باعث شده است رمز گاو صندوق را به کلی فراموش کند.

رمز گاوصندوق از یک آرایه $n$ عضوی به صورت $$a_1,a_2,...,a_{n-1},a_{n}$$تشکیل شده است و هر عضو آرایه، خود عددی صحیح و نامنفی در بازه $0$ تا $2^{31}-1$ (شامل هر دو) است. 

استاد شیفو که چندان وقت ندارد و می‌خواهد زودتر مسئولیت‌ها را به گردن پو بندازد، $m$ ثانیه از وقتش را به پو اختصاص می‌دهد. او در ثانیه $i$ درباره‌ آرایه رمز این را به یاد می‌آورد که حاصل $XOR$ عدد قسمت $x_i$ یعنی $a_{x_i}$ با عدد قسمت $y_i$ یعنی $a_{y_i}$ برابر با $k_i$ است.

او از پو می‌خواهد پس از هر بار یادآوری که درباره رمز به ذهنش می‌رسد، تعداد حالات آرایه رمز را بداند که در تمام یادآوری‌ها صدق کند.

استاد شیفو پیر شده‌است و کار با اعداد بزرگ برایش سخت است. بنابراین پو تصمیم گرفت در هر مرحله اگر عدد واقعی $x$ باشد، باقی‌مانده $x$ را بر عدد $10^9+7$ به استاد اعلام کند. ممکن است در یک مرحله، تعداد کل حالات ممکن به $0$ برسد که یعنی حافظه استاد شیفو اشتباه کرده‌است و یادآوری‌ها با هم سازگار نیستند.

پو که برقی است از شما خواسته تا در ازای نمره جبرانی، خواسته استاد شیفو را در هر ثانیه برای او محاسبه کنید.

# ورودی
در خط اول ورودی دو عدد $n$ و $m$ داده شده است.

سپس در $m$ سطر بعدی در هر سطر یک یادآوری استاد شیفو آمده است که به شکل سه عدد $x_i, y_i, k_i$ است.

$$1 \le m \le 300\ 000$$
$$2 \le  n \le 300\ 000$$
$$1 \le x_i, y_i \le n , x_i\neq y_i$$
$$0 \le k_i \le 2^{31}-1$$

# خروجی
به ازای هر یادآوری در $m$ سطر، باقیمانده جواب مساله بر $10^9+7$ را چاپ کنید.

## ورودی نمونه ۱
```
3 2
1 2 100
2 3 71
```


## خروجی نمونه ۱
```
145586002
147483634
```