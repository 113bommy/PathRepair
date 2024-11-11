import sys
import math
import collections
from pprint import pprint as pp
mod = 1000000007


def vector(size, val=0):
    vec = [val for i in range(size)]
    return vec


def matrix(rowNum, colNum, val=0):
    mat = []
    for i in range(rowNum):
        collumn = [val for j in range(colNum)]
        mat.append(collumn)
    return mat


n, s = int(input()), input()
ans = vector(n)
op = 0
cl = 0
for i in range(n):
    if s[i] == '(':
        ans[i] = op
        op ^= 1
    else:
        ans[i] = cl
        cl ^= 1
for i in ans:
    print(i, end='')
