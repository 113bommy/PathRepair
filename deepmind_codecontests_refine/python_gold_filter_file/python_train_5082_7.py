H,W,N=map(int,input().split())
ans=H
Y=[0]*H
ob=[float("inf")]*H
for i in range(N):
  x,y=map(int,input().split())
  ob[x-1]=min(ob[x-1],y-1)
for i in range(1,H):
  if ob[i]==Y[i-1]+1:
    Y[i]=Y[i-1]
  else:
    Y[i]=Y[i-1]+1
for i in range(1,H):
  if ob[i]<=Y[i]:
    ans=min(ans,i)
print(ans)
