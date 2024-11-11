from sys import stdin
from collections import *


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


n, a, mem = int(input()), arr_inp(1), defaultdict(int)

for i in range(n):
    if mem[a[i] - 1]:
        mem[a[i]] = mem[a[i] - 1] + 1
    else:
        mem[a[i]] = 1

# print(mem)
ma, ans = max(mem, key=mem.get), deque()
c = ma - mem[ma]

for i in range(n - 1, -1, -1):
    if ma == c:
        break
    if a[i] == ma:
        ans.appendleft(i + 1)
        ma -= 1

print(len(ans))
print(*ans)
