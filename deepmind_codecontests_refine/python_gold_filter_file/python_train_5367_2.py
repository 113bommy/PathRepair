n,m,k = input().strip().split()
n = int(n)
m = int(m)
k = int(k)
if k == 0:
    ans = -1
else:
    u = []
    v = []
    l = []
    for i in range(m):
        a,b,c = input().strip().split()
        u.append(int(a))
        v.append(int(b))
        l.append(int(c))
    vis = [0 for i in range(n+1)]
    k = input().strip().split()
    ans = 1000000001
    for index,item in enumerate(k):
        vis[int(item)] = 1
    for i in range(m):
        if (vis[u[i]]==1 and vis[v[i]]==0 ) or (vis[v[i]]==1 and vis[u[i]]==0):
            ans = min(ans,l[i])
    if ans == 1000000001:
        ans = -1
print(ans)