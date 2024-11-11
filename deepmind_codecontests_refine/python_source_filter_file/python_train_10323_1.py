N = int(1e+5 + 1)
input()
ns = list(map(int, input().split()))
counts = {}
us = {}

ans = 0

for i, u in enumerate(ns):
    c = us.get(u, 0)
    if c:
        counts[c] -= 1
        if counts[c] == 0:
            del counts[c]
    c += 1
    us[u] = c
    counts[c] = counts.get(c, 0) + 1
    if len(counts) == next(iter(counts)) == 1 or len(us) == 1:
        ans = i + 1
    if len(counts) == 2:
        x, y = sorted(counts)
        if x == counts[x] == 1 or y - counts[y] == 1:
            ans = i + 1
print(ans)
