import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
from collections import Counter
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

import sys
import itertools
# import numpy as np
import time
import math
from heapq import heappop, heappush
from collections import defaultdict
from collections import Counter
from collections import deque
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())
N, K = map(int, input().split())
A = list(sorted(map(int, input().split())))

def check(x):
    if x >= K:
        return True
    dp = [False] * (K + 1)
    dp[0] = True
    for j, a in enumerate(A):
        if j == x:
            continue
        for i in range(K, 0, -1):
            if i >= a:
                dp[i] |= dp[i - a]
    for i in range(K - x, K):
        if dp[i]:
            return True
    return False
left = -1
right = N
while right - left > 1:
    mid = (left + right) // 2
    if check(mid):
        right = mid
    else:
        left = mid
print(right)