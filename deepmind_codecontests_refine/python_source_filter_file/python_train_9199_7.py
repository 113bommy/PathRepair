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


def solve(S, B, K):
    MOD = 10**9 + 7
    s = set()
    
    N = len(S)
    pow = [1 for _ in range(N+1)]
    for i in range(1, N+1):
        pow[i] = pow[i-1] * 26
        pow[i] %= MOD
    
    for i in range(N-1, -1, -1):
        k, h = 0, 0
        for j in range(i, -1, -1):
            ch = S[j]
            if B[ch]:
                k += 1
            if k > K:
                # print(i, j, S[i: j+1])
                break
            h += (ord(ch) - ord('a') + 1) * pow[i-j]
            h %= MOD
            # print(S[i: j + 1], h)
            s.add(h)
    return len(s)
    
    
S = input()
B = list(input())
K = int(input())

B = {chr(ord('a') + i): False if B[i] == '1' else True for i in range(26)}
print(solve(S, B, K))

