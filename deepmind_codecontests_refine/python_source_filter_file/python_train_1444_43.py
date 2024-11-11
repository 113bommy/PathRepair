import math

n = int(input())
s = int(input())
ans = -1
if n > s:
    sqrt_n = math.ceil(math.sqrt(n))
    for b in range(2, sqrt_n + 1):
        m = n
        f = 0
        while m >= b:
            f += (m % b)
            m //= b
        f += m
        if f == s:
            ans = b
            break
    b = 2
    if ans == -1:
        for p in range(sqrt_n - 1, 0, -1):
            if (n - s) % p == 0:
                b = (n - s) // p + 1
            if n % b + n // b == s:
                ans = b
                break
elif n == s:
    ans = n + 1
print(ans)