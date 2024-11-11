def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


def arr_enu():
    return [[i + 1, int(x)] for i, x in enumerate(stdin.readline().split())]


from sys import stdin
from bisect import *

n, k = arr_inp(1)
a, ans = sorted(arr_enu(), key=lambda x: x[1]), []

for i in range(k):
    if a[-1][1] - a[0][1] <= 1:
        break
    else:
        a[-1][1] -= 1
        a[0][1] += 1
        ans.append([a[0][0], a[-1][0]])
        a.sort(key=lambda x: x[1])

print(a[-1][1] - a[0][1], len(ans))
for i in (ans):
    print(*i)
