read = lambda: map(int, input().split())
n, m = read()
a = [0] * (n + 1)
b = [0] * (n + 1)
for i in range(m):
    u, v = read()
    if u > v: u, v = v, u
    a[u] = b[v] = 1
L, R = 0, n + 1
for i in range(1, n + 1):
    if b[i] == 1:
        R = i
        break
for i in range(n, 0, -1):
    if a[i] == 1:
        L = i
        break
ans = max(0, R - L)
print(ans)
