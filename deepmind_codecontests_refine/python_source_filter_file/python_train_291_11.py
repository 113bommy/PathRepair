import sys

sys.setrecursionlimit(200002)

n, m = list(map(int, input().split()))

g = [[] for _ in range(n)]
for _ in range(m):
    l, r, d = map(int, input().split())
    l -= 1
    r -= 1
    g[l].append((r, d))
    g[r].append((l, -d))


ds = [None for _ in range(n + 1)]


def check(v):
    for next_v, d in g[v]:
        if ds[next_v] is None:
            ds[next_v] = ds[v] + d
            if check(next_v) is False:
                return False
        elif not (ds[next_v] - ds[v] == d):
            return False
    return True


valid = True
for v in range(n):
    if ds[v] is None:
        ds[v] = 0
    if check(v):
        valid = False
        break

if valid:
    print("Yes")
else:
    print("No")
