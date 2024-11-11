# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 1/7/20

"""

import collections
import time
import os
import sys
import bisect
import heapq
from typing import List


def solve(N, M, A):
    dpa = [[0 for _ in range(M+2)] for _ in range(N+2)]
    dpb = [[0 for _ in range(M+2)] for _ in range(N+2)]
    dpc = [[0 for _ in range(M+2)] for _ in range(N+2)]
    dpd = [[0 for _ in range(M+2)] for _ in range(N+2)]
    
    for r in range(1, N+1):
        for c in range(1, M + 1):
            dpa[r][c] = max(dpa[r-1][c], dpa[r][c-1]) + A[r][c]
    
    for r in range(N, 0, -1):
        for c in range(M, 0, -1):
            dpb[r][c] = max(dpb[r+1][c], dpb[r][c+1]) + A[r][c]
    
    for r in range(N, 0, -1):
        for c in range(1, M+1):
            dpc[r][c] = max(dpc[r+1][c], dpc[r][c-1]) + A[r][c]
    
    for r in range(1, N+1):
        for c in range(M, 0, -1):
            dpd[r][c] = max(dpd[r-1][c], dpd[r][c+1]) + A[r][c]

    ans = 0
    for r in range(1, N+1):
        for c in range(1, M+1):
            a = dpa[r][c-1] + dpb[r][c+1] + dpc[r+1][c] + dpd[r-1][c]
            b = dpc[r][c-1] + dpd[r][c+1] + dpa[r-1][c] + dpb[r+1][c]
            ans = max(ans, a, b)
            
    return ans


N, M = map(int, input().split())
A = [[0 for _ in range(M+2)]]
for i in range(N):
    row = [0] + [int(x) for x in input().split()] + [0]
    A.append(row)
A.append([0 for _ in range(M+2)])

print(solve(N, M, A))