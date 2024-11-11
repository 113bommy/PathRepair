n,m=map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(n)]
cd=[list(map(int,input().split())) for _ in range(m)]
for i in range(n):
  mn=100000000
  ans=0
  for j in range(m):
    d=abs(ab[i][0]-cd[j][0])+abs(ab[i][1]-cd[j][1])
    if d<mn:
      mn=d
      ans=j+1
  print(ans)