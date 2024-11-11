n=int(input())
a=[i for i in range(n)]
b=[i for i in range(n)]
for i in range(n):
  a[i],b[i]=map(int,input().split())
m=b[i]
c=0
for i in range(n):
  if(b[i]<m):
    m=b[i]
  c+=a[i]*m
print(c)