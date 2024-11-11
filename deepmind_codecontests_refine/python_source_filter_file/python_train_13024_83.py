import sys
from collections import deque
import heapq
input=sys.stdin.readline

n,s=map(int,input().split())
if(s<=n):
    print(n)
else:
    ans=s//n
    s=s%n
    if(s):
        ans+=1
    print(ans)