n,m = map(int,input().split())
edges = []
for _ in range(m):
    edges.append(list(map(int,input().split())))
ans = []
cur = ((n-1)*n)//2
par = {i:i for i in range(1,n+1)}
size = {i:1 for i in range(1,n+1)}
rank = {i:0 for i in range(1,n+1)}
def find(x):
    if x != par[x]:
        par[x] = find(par[x])
    return par[x]

def union(x,y):
    px,py = find(x),find(y)
    res = 0
    if px != py:
        res = size[px] * size[py]
        if rank[x] < rank[y]:
            par[px] = py
            size[py] += size[px]
        else:
            par[py] = px
            size[px] += size[py]
            if rank[px] == rank[py]:
                rank[px] += 1
    return res

for i in range(m-1,-1,-1):
    ans.append(cur)
    x,y = edges[i]
    cur -= union(x,y)
for i in range(m-1,-1,-1):
    print(ans[i])