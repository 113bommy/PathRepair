__author__ = 'Esfandiar'
import sys
from collections import defaultdict
input=sys.stdin.readline
n,k = map(int,input().split())
a = list(map(int,input().split()))
seen = dict()
for i in a:
    seen[i] = 1
for i in range(k):
    ans = [a[i]]
    t=1
    for j in range(1,n*k):
        if seen.get(j,-1) == -1:
            ans.append(j)
            t+=1
            seen[j] = 1
            if t==n:
                break
    print(*ans)
