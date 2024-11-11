import sys
import math
import collections
import bisect
from collections import deque as queue
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    n=int(input())
    arr=get_list()
    counter=collections.Counter(arr)
    ans=[0]
    if 1 in counter:
        ans.append(counter[1])
    else:
        ans.append(0)
    for i in range(2,n+1):
        val=0
        if i in counter:
            val=i*counter[i]
        to_ap=max(ans[i-1],ans[i-2]+val)
        ans.append(to_ap)
    print(ans[-1])
    #print(ans)