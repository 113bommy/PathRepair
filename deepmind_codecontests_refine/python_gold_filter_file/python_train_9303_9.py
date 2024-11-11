import sys
import math
import itertools
import collections


def divs(n, start=2):
    r = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if (n % i == 0):
            if (n / i == i):
                r.append(i)
            else:
                r.extend([i, n // i])
    return r
def cdiv(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def wr(arr): return ' '.join(map(str, arr))
def revn(n): return str(n)[::-1]
def prime(n):
    if n == 2: return True
    if n % 2 == 0 or n <= 1: return False
    sqr = int(math.sqrt(n)) + 1
    for d in range(3, sqr, 2):
        if n % d == 0: return False
    return True
def convn(number, base=3):
    newnumber = ''
    while number > 0:
        newnumber = str(number % base) + newnumber
        number //= base
    return newnumber


n, m, k = mi()
x = sorted(li(), reverse=True)
i = 0
if sum(x) + k -n + 1 <= m:
    print(-1)
else:
    ans = 0
    while m > k:
        k += x[i] - 1
        i += 1
        ans += 1
    print(ans)
