n, sx, sy = map(int, input().split())

k = 0
k1 = 0
k2 = 0
k3 = 0
for _ in range(n):
    x, y = map(int, input().split())
    if x > sx:
        k3 += 1
    if x < sx:
        k1 += 1
    if y > sy:
        k += 1
    if y < sy:
        k2 += 1

x = max(k, k1, k2, k3)
print(x)
if x == k:
    print(sx, sy + 1)
elif x == k1:
    print(sx - 1, sy)
elif x == k2:
    print(sx, sy - 1)
else:
    print(sx + 1, sy)