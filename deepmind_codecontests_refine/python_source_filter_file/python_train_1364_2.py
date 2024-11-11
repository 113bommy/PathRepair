import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
c = [int(i) for i in input().split()]
a = [int(i)-1 for i in input().split()]
vis = [-1]*n
ans = 0
for i in range (n):
    ind = i
    while(vis[ind]==-1):
        vis[ind]=i
        ind = a[ind]
    if vis[ind]==i:
        start = ind
        ind = a[ind]
        cost = c[ind]
        while(ind!=start):
            cost = min(cost, c[ind])
            ind = a[ind]
        ans+=cost
print(ans)