n,m=map(int,input().split())
l=[0]*m
r=[0]*m
for i in range(m):
  l[i],r[i]=map(int,input().split())
print(max(0,min(r)-max(l)))