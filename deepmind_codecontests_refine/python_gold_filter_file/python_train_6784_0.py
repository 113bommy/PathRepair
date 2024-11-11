# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 1/9/20

"""

import collections
import time
import os
import sys
import bisect
import heapq
from typing import List


def solve(A, B):
    ones = sum([int(x) for x in list(B)])
    
    A = [int(x) for x in list(A)]
    oa = sum([int(x) for x in A[:len(B)]])
    ans = 1 if ones % 2 == oa % 2 else 0
    for i in range(len(B), len(A)):
        oa += A[i]
        oa -= A[i-len(B)]
        ans += 1 if ones % 2 == oa % 2 else 0
    return ans


A = input()
B = input()
print(solve(A, B))