import sys
sys.getrecursionlimit(10**6)

N,M,K = map(int,input().split())

par = [i for i in range(N+1)]

# 木の根を求める
def root(x):
    if par[x] == x:
        return x
    else:
        par[x] = root(par[x])
        return par[x]

# xとyが同じ集合に属するか否か
def bool_same(x,y):
    return root(x) == root(y)

# xとyの属する集合を併合
def unite(x,y):
    x = root(x)
    y = root(y)
    if x != y:
        par[x] = y

AB = [list(map(int,input().split())) for i in range(M)]
CD = [list(map(int,input().split())) for i in range(K)]

for i in range(M):
    a,b = AB[i]
    unite(a,b)

member = [0 for i in range(N+1)]

for i in range(1,N+1):
    member[root(i)] += 1

ans = [member[par[i]]-1 for i in range(N+1)]

for i in range(M):
    a,b = AB[i]
    if bool_same(a,b):
        ans[a] -= 1
        ans[b] -= 1

for i in range(K):
    c,d = CD[i]
    if bool_same(c,d):
        ans[c] -= 1
        ans[d] -= 1

print(*ans[1:])
