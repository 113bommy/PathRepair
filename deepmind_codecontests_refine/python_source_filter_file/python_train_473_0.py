import bisect

n = int(input())
f = [0] + list(map(int, input().split()))
possible = True
for x in range(1, n + 1):
    if f[f[x]] != f[x]:
        possible = False
        break
if possible:
    h = sorted(set(f))
    g = [0]
    for x in range(1, n+1):
        # g.append(h.index(f[x]))
        g.append(bisect.bisect_left(h, f[x]))
    print(len(g) - 1)
    print(*g[1:])
    print(*h[1:])
else:
    print(-1)
