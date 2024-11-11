import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
n=int(input())
l=list(map(int,input().split()))
x=dc(int)
m=0
for i in range(n):
    for j in range(i+1):
        x[l[i]+l[j]]+=1
        m=max(m,x[l[i]+l[j]])
print(m)