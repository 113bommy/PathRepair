import sys

x0, y0 = list(map(int, input().split(' ')))
x1, y1 = list(map(int, input().split(' ')))
n = int(input())
s = input()
l = 0
r = 10**18

d = [[0, 0]]
dx = 0
dy = 0

for lv in s:
    if lv == 'R':
        dx += 1
    elif lv == 'L':
        dx -= 1
    elif lv == 'U':
        dy += 1
    else:
        dy -= 1
    d.append((dx, dy))


def check(x1, y1, x2, y2, t) -> bool:
    x_wind = d[-1][0] * (t // n)
    x_wind += d[t % n][0]
    y_wind = d[-1][1] * (t // n)
    y_wind += d[t % n][1]
    return abs(x1 + x_wind - x2) + abs(y_wind + y1 - y2) <= t


mid = 0
max_mid = -1
while l <= r:
    mid = (l + r) // 2
    if check(x0, y0, x1, y1, mid):
        r = mid - 1
        max_mid = mid
    else:
        l = mid + 1

if check(x0, y0, x1, y1, max_mid):
    print(max_mid)
else:
    print(-1)
