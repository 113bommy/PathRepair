from itertools import accumulate
from bisect import bisect
N = int(input())
X = list(map(int, input().split()))
mod = 10**9+7
T = [2 + i - (1+x)//2 for i, x in enumerate(X)]
T = list(accumulate(T, max))
D = [min(1 + bisect(T, i), N) - i + 1 for i in range(1, N + 1)]
ans = 1
for d in D:
    ans = (ans * d)%mod
print(ans)