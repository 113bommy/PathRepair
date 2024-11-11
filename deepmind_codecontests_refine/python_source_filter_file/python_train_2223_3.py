def dfs(g,v,vist):
    vist.append(v)
    for i in g[v]:
        if i not in vist:
            dfs(g,i,vist)

n = int(input())
xs = {}
ys = {}
g = {}

for p in range(n):
    x,y = map(int, input().split())
    g[(x,y)] = []
    if x in xs:
        g[(x,y)].append((x,xs[x]))
        g[(x,xs[x])].append((x,y))
    elif y in ys:
        g[(x,y)].append((ys[y],y))
        g[(ys[y],y)].append((x,y))

    xs[x] = y
    ys[y] = x

count = 0
vist = []
for v in g.keys():
    if v not in vist:
        count += 1
        dfs(g,v,vist)

print(count-1)


