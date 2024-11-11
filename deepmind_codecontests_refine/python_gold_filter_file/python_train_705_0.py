n,m=map(int,input().split())
ks=[]
for i in range(m):
  t=list(map(int,input().split()))
  ks.append(t)
p=list(map(int,input().split()))

ans=0
for i in range(1<<n):
  on=0
  for j in range(m):
    cnt=0
    for k in range(ks[j][0]):
      if 1<<(ks[j][k+1]-1) & i:
        cnt+=1
    if cnt%2==p[j]:
      on+=1
    if on==m:
      ans+=1
print(ans)