n,m=map(int,input().split())
vis=[]
for i in range(n):
    vis.append(0)
for i in range(m):
    a,b=map(int,input().split())
    vis[a-1]=1
    vis[b-1]=1
center=-1
for i in range(n):
    if vis[i]==0:
        center=i
        break
print(n-1)
for i in range(n):
    if i==center:
        continue
    print(i,center)