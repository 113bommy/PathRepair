n,m = map(int,input().split())
p = list(map(lambda x:int(x)-1,input().split()))
par = [i for i in range(n)]
rank = [0]*n

def find(x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]

def unite(x, y):
    x = find(x)
    y = find(y)
    if rank[x] < rank[y]:
        par[x] = y
    else:
        par[y] = x
    if rank[x] == rank[y]:
        rank[x] += 1

def same(x, y):
    return find(x) == find(y)

for i in range(m):
    x,y = map(int,input().split())
    unite(x-1,y-1)

ans = 0
for i in range(n):
    if same(i,p[i]):
        ans += 1
print(ans)