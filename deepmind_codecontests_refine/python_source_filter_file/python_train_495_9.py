import math

n = int(input())
x = list(map(int, input().split()))
mod = 10 ** 9 + 7

fac = math.factorial(n - 1)


def pow(n, p):
    res = 1
    while p > 0:
        if p % 2 == 0:
            n = n ** 2 % mod
            p //= 2
        else:
            res = res * n % mod
            p -= 1
    return res % mod


res = 0
for i in range(n - 1):
    d = x[n - 1] - x[i]
    res += (d * fac * pow(i + 1, mod - 2)) % mod

print(res % mod)
