n, m, k = map(int, input().split())
s, p = 0, [[] for i in range(m + 1)]
for i in range(n):
    a, b = map(int, input().split())
    p[a].append(b)
for a in range(1, m + 1):
    s += min(p[a])
print(min(k, s - m))