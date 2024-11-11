import bisect
import collections
import copy
import functools
import heapq
import itertools
import math
import sys
import string
import random
from typing import List
sys.setrecursionlimit(99999)


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    mp= collections.defaultdict(int)
    cnt= collections.defaultdict(int)
    ans = 0
    pre = 0
    for i,c in enumerate(arr):
        ans+=mp[c]*(n-i)
        mp[c]+=(i+1)
        cnt[c]+=1
    print(ans)
    