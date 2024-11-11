H,W,N=map(int,input().split())
ans=W
Y=[0]*W
ob=[float("inf")]*W
for i in range(N):
  x,y=map(int,input().split())
  ob[x-1]=min(ob[x-1],y-1)
for i in range(1,W):
  if ob[i]==Y[i-1]+1:
    Y[i]=Y[i-1]
  else:
    Y[i]=Y[i-1]+1
for i in range(1,W):
  if ob[i]<=Y[i]:
    ans=min(ans,i)
print(ans)
