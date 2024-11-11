import math
import bisect

from math import gcd, floor, sqrt, log
from collections import defaultdict as dd

I = lambda: int(input())
tup = lambda: map(int, input().split())
lst = lambda: list(map(int, input().split()))

t = 1
#t = I()

while t:

    n = I()
    arr = [list(input()) for i in range(n)]

    if (arr[0][0] == '.') or (arr[0][n - 1] == '.') or (arr[n - 1][0] == '.') or (arr[n - 1][n - 1] == '.'):
        print("NO")
        break

    for i in range(1,n - 1):
        for j in range(1, n - 1):
            if arr[i][j] == '.':
                if arr[i - 1][j] == '.' and arr[i][j + 1] == '.' \
                   and arr[i - 1][j] == '.' and arr[i][j - 1] == '.':
                    arr[i - 1][j] = '#'
                    arr[i][j + 1] = '#'
                    arr[i + 1][j] = '#'
                    arr[i][j - 1] = '#'
                    arr[i][j] = '#'

    flag = False
    for i in range(n):
        for j in range(n):
            if arr[i][j] == '.':
                flag = True
                break
        if flag:
            break

    if flag:
        print("NO")
    else:
        print("YES")

    t -= 1


    