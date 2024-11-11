# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 2020/6/30

"""

import collections
import time
import os
import sys
import bisect
import heapq
from typing import List


def solve(N, A):
    B = list(sorted(set(A)))
    B.sort()
    to = {v:i for i, v in enumerate(B)}
    A = [to[v] for v in A]
    
    dp = [1 for i in range(N+1)]
    vi = [-1 for _ in range(N+1)]
    
    for i, v in enumerate(A):
        dp[i] = max(dp[i], (dp[vi[v-1]] if v-1 >= 0 and vi[v-1] >= 0 else 0) + 1)
        vi[v] = i
    
    return N - max(dp)
    
    


if __name__ == '__main__':
    T = int(input())
    ans = []
    for ti in range(T):
        N = int(input())
        A = [int(x) for x in input().split()]
        ans.append(solve(N, A))
    
    print('\n'.join(map(str, ans)))


    