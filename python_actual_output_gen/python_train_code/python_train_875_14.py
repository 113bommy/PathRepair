n,m=map(int,input().split())
a=[0]*n
b=[0]*n
for i in range(m):
  a[i],b[i]=map(int,input().split())
for j in range(n):
  print(a.count(j+1)+b.count(j+1))