# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 12/30/19

"""

import collections
import time
import os
import sys
import bisect
import heapq
from typing import List


d = ['']
N = int(input())
for i in range(N):
    s = input()
    if s == 'pwd':
        print('/'.join(d) + '/')
    else:
        s = s.split(' ')[1]
        if s.startswith('/'):
            d = []
        for v in s.split('/'):
            if v == '..':
                d.pop()
            elif v == '.':
                pass
            else:
                d.append(v)