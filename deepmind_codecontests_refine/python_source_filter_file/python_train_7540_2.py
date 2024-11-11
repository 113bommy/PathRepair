n, a = int(input()), list(map(int, input().split()))
if n & 1: a.append(0)
x, t = 0, [[' '] * (sum(a) + 10) for i in range(2001)]
y = u = v = 1000
for i in range(0, n, 2):
    for j in range(a[i]):
        t[y][x] = '/'
        x += 1
        y += 1
    v = max(v, y)
    for j in range(a[i + 1]):
        y -= 1
        t[y][x] = '\\'
        x += 1
    u = min(u, y)
for i in range(v - 1, u - 1, -1): print(''.join(t[i]))