import sys
import math
from decimal import *

line = lambda: list(int(x) for x in input().split())

def pow(n, k, p):
    if k == 0:
        return 1 % p
    if k % 2 == 1:
        return pow(n, k - 1, p) * n % p
    t = pow(n, k / 2, p)
    return t * t % p;

test = int(input())
for i in range(0, test):
    x = int(input())
    x = x * 10 ** 5
    x += (2 ** 16 - x % 2 ** 16) % 2 ** 16
    if x % 5 == 0:
        x += 2 ** 16;
    res = 0
    for i in range(1, 16 + 1):
        while pow(2, res, 5 ** i) != x % 5 ** i:
            if i == 1:
                res += 1
            else:
                res += 4 * 5 ** (i - 2)
    res += 4 * 5 ** 15
    print(res)
