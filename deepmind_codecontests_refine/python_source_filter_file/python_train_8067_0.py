f = lambda: map(int, input().split())
n, m = f()
t = list(f())
s = [0] * 301
d = s[:]
for i in t: d[i] += 1
for i in t * min(m, 2 * n): s[i] = max(s[:i]) + 1
print(max(s) + max((m - n * 2) * max(d), 0))