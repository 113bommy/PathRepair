
from math import log2
n = int(input())
p = [0] * (n + 1)
def f(n):
    k = int(log2(n))
    while k:
        i = 1
        while (1 << k) + i - 1 <= n:
            p[(1 << k) + i - 1] = (1 << k) - i
            p[(1 << k) - i] = (1 << k) + i - 1
            i += 1
        n = (1 << k) - i
        if not n:
            break
        k = int(log2(n))
if n & 1:
    print('NO')
else:
    print('YES')
    f(n)
    print(*p[1:])

if n < 6 or int(log2(n)) == n:
    print('NO')
else:
    print('YES')
    if n == 6:
        print('3 6 2 5 1 4')
    elif n == 7:
        print('7 3 6 5 1 2 4')
    else:
        print('7 3 6 5 1 2 4', end=' ')
        k = 3
        while (1 << k) < n:
            for i in range((1 << k) + 1, min(1 << k + 1, n + 1)):
                print(i, end=' ')
            print(1 << k, end=' ')
            k += 1

