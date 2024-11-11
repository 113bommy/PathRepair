N, M = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(M)]

def find(x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]


def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    
    if rank[x] == rank[y]:
        rank[x] += 1
    elif rank[x] < rank[y]:
        x, y = y, x
        
    par[y] = x
    size[x] += size[y]


def same(x, y):
    return find(x) == find(y)


par = list(range(N))
rank = [0] * N
size = [1] * N

ans = [N * (N - 1) // 2] * M
for i, (a, b) in enumerate(X[:0:-1]):
    if same(a - 1, b - 1):
        ans[i + 1] = ans[i]
        continue

    ans[i + 1] = ans[i] - size[find(a - 1)] * size[find(b - 1)]
    unite(a - 1, b - 1)

print(*ans, sep="\n")
