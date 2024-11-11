from math import floor

n, k, t = map(int, input().split())
l = [0 for i in range(n)]

g = t / 100 * n
gl = floor(g)

for i in range(gl):
    l[i] = k

if gl < n:
    l[gl] = floor((g - gl) * k)

for item in l:
    print(item, end = ' ')
