import bisect
from itertools import accumulate

n, m = map(int, input().split())
shrinks = []
total = 0
for _ in range(n):
    a, b = map(int, input().split())
    total += a
    shrinks.append(a - b)

shrinks.sort(reverse=True)
acc = list(accumulate(shrinks))
# print(acc, total, m)
if total >= m:
    print(0)
elif total - acc[-1] > m:
    print(-1)
else:
    to_shrink = total - m
    i = bisect.bisect_left(acc, to_shrink)
    print(i + 1)
