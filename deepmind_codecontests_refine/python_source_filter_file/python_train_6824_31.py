import math
import sys
from bisect import bisect_right, bisect_left, insort_right
from collections import Counter, defaultdict
from heapq import heappop, heappush
from itertools import accumulate
from sys import stdout

R = lambda: map(int, input().split())
n = int(input())
arr = list(R())
ss = [input() for _ in range(n)] + ['']
dp = [[0, 0] for i in range(n + 1)]
for i in range(n):
    dp[i][0] = min(dp[i - 1][0] if ss[i] >= ss[i - 1] else math.inf, dp[i - 1][1] if ss[i] >= ss[i - 1][::-1] else math.inf)
    dp[i][1] = arr[i] + min(dp[i - 1][0] if ss[i][::-1] >= ss[i - 1] else math.inf, dp[i - 1][1] if ss[i][::-1] >= ss[i - 1] else math.inf)
print(min(dp[n - 1]) if min(dp[n - 1]) < math.inf else -1)