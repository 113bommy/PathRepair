import math
from collections import defaultdict, Counter
from bisect import bisect_left
from sys import stdin

input = stdin.readline
    
t = int(input())
# a = list(map(int, input().split()))
for _ in range(t):
    n,m,k = list(map(int, input().split()))
    if m > n*(n-1)//2 or m < n-1:
        print('NO')
    if k <= 1:
        print('NO')
    elif m == 0 or n ==1:
        print('YES')
    elif m < n-1 or m > (n*(n-1))//2:
        print('NO')
    elif m == (n*(n-1))//2:
        if k > 2:
            print('YES')
        else:
            print('NO')
    elif k > 3:
        print('YES')
    else:
        print('NO')
    