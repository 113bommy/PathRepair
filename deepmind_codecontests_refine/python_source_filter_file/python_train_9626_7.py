__author__ = 'PrimuS'

from bisect import bisect_right

n = int(input())
t1 = [int(x) for x in input().split()]
m = int(input())
t2 = [int(x) for x in input().split()]

t1.sort()
t2.sort()

best = [3 * n, 3 * m]

for i in range(n):
    a = 2 * i + 3 * (n - i)
    u = bisect_right(t2, t1[i])
    b = u * 2 + 3 * (m - u)
    if a - b > best[0] - best[1]:
        best[0] = a
        best[1] = b


if 2 * n - 2 * m > best[0] - best[1]:
    best = [2 * n, 2 * m]

print(best[0], ":", best[1], sep='')
