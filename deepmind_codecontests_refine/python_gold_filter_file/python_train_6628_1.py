import random

n = int(input())
v = []
a = []
for i in range(n):
    a.append(i)

for _ in range(0, n):
    x, y = map(int, input().split())
    v.append([x, y, x*x+y*y])

while 1>0:
    x = 0
    y = 0
    ans = [0]*n
    random.shuffle(a)
    for i in range(n):
        if (x+v[a[i]][0])**2+(y+v[a[i]][1])**2 <= (x-v[a[i]][0])**2+(y-v[a[i]][1])**2:
            x += v[a[i]][0]
            y += v[a[i]][1]
            ans[a[i]] = 1
        else:
            x -= v[a[i]][0]
            y -= v[a[i]][1]
            ans[a[i]] = -1
    if x*x+y*y <= 1500000**2:
        print(*ans)
        break

