def find(x):
    if par[x] < 0:
        return x
    else:
        par[x] = find(par[x])
        return par[x]

def same(x, y):
    return find(x) == find(y)

def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    if par[x] > par[y]:
        x, y = y, x
    par[x] += par[y]
    par[y] = x


N, M = map(int, input().split())
par = [-1 for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    unite(a - 1, b - 1)

cnt = -1
num = {0}

for i in par:
  if i <= -1:
    cnt += 1

print(cnt)