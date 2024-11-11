n,m=map(int,input().split())
a=[0]*n
b=[0]*n
for i in range(n):
  a[i],b[i]=map(int,input().split())
for j in range(m):
  print(a.count(m+1)+b.count(m+1))