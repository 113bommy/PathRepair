N, M = map(int, input().split())
P=[]
for i in range(N):
  x,y=map(int, input().split())
  P.append([x,y])
C=[]
for i in range(M):
  a,b=map(int, input().split())
  C.append([a,b])

for p in P:
  mind=10000000
  for j in range(M):
    d=abs(p[0]-C[j][0])+abs(p[1]-C[j][1])
    if d<mind:
      ans=j+1
      mind=d
  print(ans)

