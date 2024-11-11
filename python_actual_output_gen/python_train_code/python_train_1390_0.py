n,m,x=map(int,input().split())
ans=999999999999999999
a=[0]*m
for i in range(n):
  a[i]=list(map(int,input().split()))
for i in range(2**n):
  t=[0]*m
  temp=0
  for j in range(n):
    if (i>>j)&1:
      temp=temp+a[j][0]
      for k in range(m):
        t[k]=t[k]+a[j][k+1]
  if min(t)>=x:
    ans=min(ans,temp)
if ans==999999999999999999:
  print(-1)
else:
  print(ans)