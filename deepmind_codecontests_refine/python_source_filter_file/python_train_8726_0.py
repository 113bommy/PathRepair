H,W,D=map(int,input().split())
d=[[0,0] for i in range(H*W+1)]
d2=[0 for i in range(H*W+1)]
for j in range(H):
  a=[int(x) for x in input().split()]
  for k in range(W):
    d[a[k]]=[j+1,k+1]
for l in range(D+1,H*W+1-D):
  d2[l]=abs(d[l][0]-d[l-D][0])+abs(d[l][1]-d[l-D][1])
for m in range(D+1,H*W+1-D):
  d2[m]+=d2[m-D]
Q=int(input())
for i in range(Q):
  a,b=map(int,input().split())
  if a==b:
    print(0)
  else:
    ans=d2[b]-d2[a]
    print(ans)