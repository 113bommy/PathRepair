import collections
import math

t = int(input())

for _ in range(t):
    # n, k = map(int, input().split())
    n = int(input())
    a = collections.Counter(list(map(int, input().split())))
    mx = max(a.values())
    if mx > n // 2:
        print(n - 2 * (n - mx))
    else:
        print(0)