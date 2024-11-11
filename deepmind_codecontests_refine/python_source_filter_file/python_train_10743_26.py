from functools import reduce

from typing import List, Tuple

t = int(input())
for __ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    sorted_idc = sorted(range(1, n+1), key=lambda i: a[i-1])
    if m < n:
        print(-1)
    if n == 2:
        print(-1)
    else:
        print(2*sum(a) + (m-n)*(a[sorted_idc[0]]+a[sorted_idc[1]]))
        for i in range(n-1):
            print(sorted_idc[i], sorted_idc[i+1])
        print(sorted_idc[0], sorted_idc[n-1])
        for i in range(m-n):
            print(sorted_idc[0], sorted_idc[1])
