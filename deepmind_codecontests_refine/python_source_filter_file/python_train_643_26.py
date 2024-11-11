'''input
3 2
192
'''
# A coding delight
from sys import stdin


def counter(c):
    if c == 'B':
        return 'W'
    return 'B'

# main starts
n, sx, sy = list(map(int, stdin.readline().split()))
less_y = 0; less_x = 0; more_x = 0; more_y = 0
for _ in range(n):
    x, y = list(map(int, stdin.readline().split()))
    x -= sx
    y -= sy
    if x < 0:
        less_x += 1
    elif x > 0:
        more_x += 1
    if y < 0:
        less_y += 1
    elif y > 0:
        more_y += 1

ans = 0
ax = 0; ay = -1
if ans < more_y:
    ans = more_y
    ax = 0; ay = 1
if ans < less_y:
    ans = less_y
    ax = 0; ay = -1
if ans < more_x:
    ans = more_x
    ax = 1; ay = 0
if ans < less_x:
    ans = less_y
    ax = -1; ay = 0

print(ans)
print(ax + sx, ay + sy)
