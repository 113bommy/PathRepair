import sys
input = sys.stdin.readline
import math
import copy
import bisect
import collections
from collections import deque
import heapq
from collections import defaultdict

t = int(input())
for f in range(t):
    n,k = map(int,input().split())
    div = []
    for i in range(1,27):
        if k%i == 0:
            div.append(i)
    s = list(input().rstrip())
    c = collections.Counter(s)
    a = c.most_common()
    freq = []
    for i in a:
        freq.append(i[1])
    ans = 0
    for i in div:
        j = 1
        tmp = 0
        while j*i <=n:
            memo = 0
            for l in range(len(freq)):
                memo += freq[l]//j
            if memo >= i:
                tmp = j*i
                j += 1
            else:
                break

        ans = max(ans,tmp)
    print(ans)