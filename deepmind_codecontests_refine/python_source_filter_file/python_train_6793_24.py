import collections
import bisect

n, p = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.sort()
memo = collections.deque()
minx, maxx = 0, 9999999999999
for i in reversed(a):
    minx = max(minx - 1, i)
    if len(memo) == p - 1:
        maxx = min(maxx, memo[0] - 1)
        memo.popleft()
    memo.append(i)
if minx > maxx:
    print(0)
else:
    print(maxx - minx + 1)
    for i in range(minx, maxx + 1):
        print(i, end=' ')

    
        




