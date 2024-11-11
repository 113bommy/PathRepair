import math,sys,re,itertools,pprint,collections,copy
rs,ri,rai,raf=input,lambda:int(input()),lambda:list(map(int, input().split())),lambda:list(map(float, input().split()))

n = ri()
x0, y0 = rai()

rays = [
    [ [], lambda x, y: x == x0 and y > y0 ],             # top
    [ [], lambda x, y: x == x0 and y < y0 ],             # bottom
    [ [], lambda x, y: y == y0 and x > x0 ],             # right
    [ [], lambda x, y: y == y0 and x < x0 ],             # left
    [ [], lambda x, y: x - x0 == y - y0 and x > x0 ],    # right top
    [ [], lambda x, y: x - x0 == y - y0 and x < x0 ],    # left bottom
    [ [], lambda x, y: x - x0 == -(y - y0) and x > x0 ], # right bottom
    [ [], lambda x, y: x - x0 == -(y - y0) and x < x0 ], # left top
]

for i in range(n):
    t = input().split()
    x, y = int(t[1]), int(t[2])
    t = (t[0], x, y)
    for k, v in rays:
        if v(x, y):
            k.append(t)

dist = lambda a: abs(x0 - a[1]) + abs(y0 - a[2])

flag = False
for i, (k, v) in enumerate(rays):
    k.sort(key=dist)
    if len(k) > 0 and i > 3 and k[0][0] in "BQ":
        flag = True
        break
    if len(k) > 0 and i <= 3 and k[0][0] == "R":
        flag = True
        break

print("YES" if flag else "NO")
