import traceback
from functools import lru_cache
from itertools import accumulate

try:
    N = int(input())
    nums = list(map(int, input().split()))
    # dp = [0] * 2
    # ans = 0
    acc = [0] * N
    tot = 0
    for i in range(N-1, -1, -1):
        tot += nums[i]
        acc[i] = tot
    @lru_cache(None)    
    def dp(i):
        if i == N: return 0
        return max(dp(i+1), acc[i] - dp(i+1))
    b = dp(0)
    print([dp(i) for i in range(N)])
    a = acc[0] - b
    print(a, b)
except Exception:
    traceback.print_exc()