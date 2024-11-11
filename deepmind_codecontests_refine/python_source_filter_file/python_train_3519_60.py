from itertools import combinations
from bisect import bisect_left
N, K = map(int,input().split())
A = list(map(int,input().split()))

ans=0

for i,j in combinations(range(N+2),2):
  l = sorted(A[0:i]+A[j-1:N])
  if len(l)<=K:
    m = bisect_left(l,0)
  	ans = max(ans,sum(l[min(K-len(l),m):]))
print(ans)
