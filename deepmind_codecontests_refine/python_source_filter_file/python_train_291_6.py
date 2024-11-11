n, m = map(int, input().split())
par = [i for i in range(n)]
diff = [0] * n


def find(x):
    if par[x] == x:
        return x, 0
    else:
        a, b = find(par[x])
        par[x] = a
        diff[x] += b
        return a, diff[x]


def unite(x, y, z):
    s, ws = find(x)
    t, wt = find(y)
    # print(ws, wt)
    if s == t:
        if ws - wt == z:
            pass
        else:
            print('No')
            exit(0)
    else:
        if ws < z + wt:
            par[s] = t
            diff[s] = z + wt - ws
        else:
            par[t] = s
            diff[s] = ws - z - wt


for _ in range(m):
    l, r, d = map(int, input().split())
    unite(l - 1, r - 1, d)

print('Yes')