import sys
import math
import collections
from pprint import pprint as pp
mod = 998244353
MAX = 10**10


def vector(size, val=0):
    vec = [val for i in range(size)]
    return vec


def matrix(rowNum, colNum, val=0):
    mat = []
    for i in range(rowNum):
        collumn = [val for j in range(colNum)]
        mat.append(collumn)
    return mat


n = int(input())
a, b = list(map(int, input().split())), list(map(int, input().split()))
for i in range(n):
    a[i] *= (i + 1) * (n - i)
a.sort()
b.sort()
ans = 0
for i in range(n):
    ans = (ans + a[i] * b[n - i - 1]) % mod
print(ans)
