import itertools
n, k = map(int, input().split())
p = []

vy = set()
vx = set()
for i in range(n):
    x, y = map(int, input().split())
    p.append((y,x))
    vy.add(y)
    vx.add(x)
vy = sorted(list(vy))
vx = sorted(list(vx))

min_area = float('inf')


for y in itertools.combinations(vy, r=2):
    for x in itertools.combinations(vx, r=2):
        cnt = 0
        for i in range(n):
            if y[0] <= p[i][0] <= y[1] and x[0] <= p[i][1] <= x[1]:
                cnt += 1
        if cnt >= k:
            min_area = min(min_area, (y[1]-y[0]) * (x[1]-x[0]))
print(min_area)