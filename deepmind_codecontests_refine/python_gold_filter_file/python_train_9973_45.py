import math
N = int(input())
n = 100

x = [None] * N
y = [None] * N
for i in range(N):
    x[i], y[i] = map(int, input().split())

ans = 0
for i in range(n):
    theta = (2 * math.pi / n) * i
    c = math.cos(theta)
    s = math.sin(theta)
    tmp_x = 0
    tmp_y = 0
    for j in range(N):
        if x[j] * c + y[j] * s > 0:
            tmp_x += x[j]
            tmp_y += y[j]
    if tmp_x**2 + tmp_y**2 > ans**2:
        ans = math.sqrt(tmp_x**2 + tmp_y**2)

print(ans)
