from math import *
n = int(input())
engine = [list(map(int, input().split())) for i in range(n)]

args = []
for i in range(n):
    x, y = engine[i]
    if x == 0:
        if y < 0:
            args.append((-pi/2, x, y))
        elif y > 0:
            args.append((pi/2, x, y))

    elif y == 0:
        if x > 0:
            args.append((0, x, y))
        elif x < 0:
            args.append((pi, x, y))

    else:
        args.append((atan2(y, x), x, y))

args.sort()
l = len(args)
args = args[:] + args[:]
ans = 0
for i in range(1, l+1):
    for j in range(l):
        x, y = 0, 0
        for k in range(j, j+i):
            x += args[k][1]
            y += args[k][2]
        ans = max(ans, (x**2+y**2)**(1/2))

print(ans)
