ma = lambda :map(int,input().split())
lma = lambda :list(map(int,input().split()))
tma = lambda :tuple(map(int,input().split()))
ni = lambda:int(input())
yn = lambda fl:print("Yes") if fl else print("No")
import collections
import math
import itertools
import heapq as hq
ceil = math.ceil

n = ni()
A = lma()
co = collections.Counter(A)
ans = 0
for num,cnt in co.items():
    if num<cnt:
        ans+=(num-cnt)
    if num>cnt:
        ans+=cnt
print(ans)
