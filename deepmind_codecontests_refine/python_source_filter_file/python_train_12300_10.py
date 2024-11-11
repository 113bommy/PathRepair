import sys
from bisect import bisect_left as bl
n, m, ta, tb, k = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split())) + [10**10]*(k+1)

if min(len(A), len(B)) <= k:
    print(-1)
    sys.exit()

ans = -1
for i, a in enumerate(A):
    xi = bl(B, a+ta)
    ans = max(ans, B[xi+k-i]+tb)
if ans == 10**10:
    print(-1)
    sys.exit()
print(ans)