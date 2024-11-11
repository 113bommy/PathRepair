h,w=map(int,input().split())
d=[list(map(int,input().split())) for _ in range(10)]
for i in range(10):
  for j in range(10):
    for k in range(10):
      d[i][j]=min(d[i][j],d[i][k]+d[k][j])
ans=0
for _ in range(h):
  arr=list(map(int,input().split()))
  for i in arr:
    if abs(i)!=1:
      ans+=d[i][1]
print(ans)