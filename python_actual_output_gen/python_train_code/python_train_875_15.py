n,m=map(int,input().split())
road=[0]*n
for _ in range(m):
  a,b=map(int,input().split())
  road[a]+=1
  road[b]+=1

for i in range(n):
  print(road[i])