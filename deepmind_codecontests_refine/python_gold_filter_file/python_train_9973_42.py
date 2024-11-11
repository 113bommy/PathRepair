import sys
input = sys.stdin.readline
import math
# キュー(FIFO)
from collections import deque
from operator import itemgetter


N = int(input())
XY1 = []
XY2 = []
for _ in range(N):
    x, y = map(int, input().split())
    theta = math.atan2(y, x)
    if y == 0 and x < 0:
        theta -= 2*math.pi
    if theta < 0:
        XY1.append((x, y, theta))
    else:
        XY2.append((x, y, theta))

XY1.sort(key=itemgetter(2))
XY2.sort(key=itemgetter(2))

q1 = deque()
q2 = deque()
for xy1 in XY1:
    q1.append(xy1)
for xy2 in XY2:
    q2.append(xy2)

ans = 0
for _ in range(N+4):
    px, py = 0, 0
    mx, my = 0, 0
    for xy1 in q1:
        px += xy1[0]
        py += xy1[1]
    for xy2 in q2:
        mx += xy2[0]
        my += xy2[1]
    dp = math.sqrt(px**2+py**2)
    if dp > ans:
        ans = dp
    dm = math.sqrt(mx**2+my**2)
    if dm > ans:
        ans = dm
    
    if len(q1) == 0:
        xy2 = q2.popleft()
        q1.append(xy2)
    elif len(q2) == 0:
        xy1 = q1.popleft()
        q2.append(xy1)
    else:
        xy1 = q1[0]
        xy2 = q2[0]
        theta1 = xy1[2]
        theta2 = xy2[2]
        if theta1 + math.pi < theta2:
            q1.popleft()
            q2.append((xy1[0], xy1[1], theta1+2*math.pi))
        else:
            q2.popleft()
            q1.append((xy2[0], xy2[1], theta2))

print(ans)