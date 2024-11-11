# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 12/18/18

"""

import collections
import time
import os
import sys
import bisect
import heapq


n, x1, x2 = map(int, input().split())

C = [int(x) for x in input().split()]
C = [(v, i+1) for i, v in enumerate(C)]
C.sort()


def check(x1, x2, rev):
    
    r = n
    p1, p2 = [], []
    for i in range(n-1, -1, -1):
        if C[i][0] * (n-i) >= x1:
            r = i
            p1 = [v[1] for v in C[i:]]
            break
    
    if p1:
        for i in range(r, -1, -1):
            if C[i][0] * (r-i) >= x2:
                p2 = [v[1] for v in C[i: r]]
                if rev:
                    p1, p2 = p2, p1
                print('YES')
                print('{} {}'.format(len(p1), len(p2)))
                print(' '.join(map(str, p1)))
                print(' '.join(map(str, p2)))
                exit(0)

check(x1, x2, False)
check(x2, x1, True)
print('No')
