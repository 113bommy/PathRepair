from math import*
n, s = map(int, input().split())
dist = []
for i in range(n):
    a, b, c = map(int, input().split())
    dist.append((a*a + b*b, c))
dist = sorted(dist)
i = 0
while s < 1000000 and i < n:
    s += dist[i][1]
    i += 1
if s < 1000000:
    print(-1)
elif i == 0:
    print(0)
else:
    print(sqrt(dist[i - 1][0]))