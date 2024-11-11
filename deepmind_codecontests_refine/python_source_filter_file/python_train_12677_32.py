from bisect import bisect_right
from itertools import accumulate

N, M, K, *AB = map(int, open(0).read().split())
A, B = AB[:N], AB[N:]

A = [0] + list(accumulate(A))
B = [0] + list(accumulate(B))

ans = 0
for i, a in enumerate(A):
    if K - a <= 0:
        break
    ans = max(ans, bisect_right(B, K - a) + i - 1)

print(ans)