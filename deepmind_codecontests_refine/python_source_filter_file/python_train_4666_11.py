road = [0]*4
for i in range(3):
  a,b = map(int,input().split())
  road[a-1]+=1
  road[b-1]+=1
if max(road)>=3:
  print('No')
else:
  print('Yes')