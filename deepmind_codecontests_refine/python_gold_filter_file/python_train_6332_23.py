n, m = map(int, input().split())
p = list(map(lambda x: int(x) - 1, input().split()))
xy = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(m)]

par = [i for i in range(n)]
rank = [0 for _ in range(n)]


def root(x):
    if par[x] == x:
        return x
    par[x] = root(par[x])
    return par[x]


def is_same(x, y):
    return root(x) == root(y)


def union(x, y):
    x = root(x)
    y = root(y)
    if x == y:
        return
    if rank[x] < rank[y]:
        par[x] = y
    else:
        par[y] = x
        if rank[x] == rank[y]:
            rank[x] += 1


for x, y in xy:
    union(x, y)

count = 0
for i, p_i in enumerate(p):
    count += 1 if is_same(i, p_i) else 0
print(count)
