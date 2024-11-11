from collections import *
from sys import stdin


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


n, m = arr_inp(1)
a, mem, ans, en = arr_inp(1), defaultdict(lambda: [0, 0]), deque(), n - 1

for i in range(m):
    t, r = arr_inp(1)
    mem[r] = [t, i]

for i in range(n - 1, -1, -1):
    if not mem[i + 1][0]:
        ans.appendleft(a[i])
        en -= 1
    else:
        break

tem, last, time = deque(sorted(a[:en + 1])), 0, -1

for j in range(en, -1, -1):
    if mem[j + 1][0] == 1 and mem[j + 1][1] > time:
        ans.appendleft(tem.pop())
        last, time = 1, mem[j + 1][1]

    elif mem[j + 1][0] == 2 and mem[j + 1][1] > time:
        ans.appendleft(tem.popleft())
        last, time = 2, mem[j + 1][1]

    elif last == 1:
        ans.appendleft(tem.pop())

    else:
        ans.appendleft(tem.popleft())

print(*ans)
