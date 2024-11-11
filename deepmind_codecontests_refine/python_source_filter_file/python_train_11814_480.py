import math
m, n = map(int, input().split())
a = 2
if n > m and n % 2 == 0:
    res = m * round(n / a)
    print(res)
elif n > m and n % 2 != 0:
    res = m * (n / a)
    print(int(res))
else:
    res = round(n / a) * round(m / a)
    print(res)
