n,m=map(int,input().split())
p=[[]for _ in range(n)]
c=[0]*n
import sys
sys.setrecursionlimit(n)
for i in range(m):
    x,y=map(int,input().split())
    p[x-1].append(y-1)
from functools import lru_cache
@lru_cache(maxsize=n)
def l(k):
    return max([l(i)for i in p[k]]+[0])+1
print(max([l(i)for i in range(n)])-1)