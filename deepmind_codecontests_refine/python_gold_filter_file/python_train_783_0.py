rd = lambda: map(int, input().split())
n, w, v, u = rd()
p = []
for i in range(n):
    x, y = rd()
    p.append([x - y / u * v, x / v, y])
p.sort()
if all(x >= 0 for x, y, z in p) or all(x <= 0 for x, y, z in p):
    print(w / u)
else:
    print(p[-1][1] + (w - p[-1][2]) / u)
