import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left,bisect
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
for _ in range(int(input())):
    n=int(input())
    s=input()[:-1]
    l,r=-1,-1
    for i in range(n-1):
        if s[i]!=s[i+1]:
            l,r=i+1,i+2
            break
    print(l,r)
            