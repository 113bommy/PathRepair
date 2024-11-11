from collections import defaultdict
n = int(input())
x = [0] * n
y = [0] * n
dir = [0] * n
INF = 10**8


def g(v):
    v.sort(key=lambda x: x[0])
    ret = INF
    for i in range(1, len(v)):
        if v[i - 1][1] == 0 and v[1][1] != 0:
            ret = min(ret, v[i][0] - v[i - 1][0])
    return ret


def f(d):
    ret = INF
    for k, v in d.items():
        ret = min(ret, g(v))
    return ret


for i in range(n):
    # x[i], y[i], c = map(int, input().split())
    sx, sy, c = input().split()
    x[i] = int(sx)
    y[i] = int(sy)
    if c == 'U':
        dir[i] = 0
    if c == 'R':
        dir[i] = 1
    if c == 'D':
        dir[i] = 2
    if c == 'L':
        dir[i] = 3

ans = INF
for ri in range(4):
    # UD
    d = defaultdict(list)
    for i in range(n):
        if dir[i] != 0 and dir[i] != 2:
            continue
        d[x[i]].append((y[i], dir[i]))
    ans = min(ans, f(d) * 5)
    # UR
    d2 = defaultdict(list)
    for i in range(n):
        if dir[i] != 0 and dir[i] != 1:
            continue
        d2[x[i] + y[i]].append((y[i], dir[i]))
    ans = min(ans, f(d2) * 10)

    # rotate
    for i in range(n):
        px = x[i]
        py = y[i]
        x[i] = py
        y[i] = -px
        dir[i] = (dir[i] + 1) % 4
if ans >= INF:
    print('SAFE')
else:
    print(ans)
