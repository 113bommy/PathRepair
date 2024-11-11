K,S=map(int,input().split())
points=0
for i in range(K+1):
  for j in range(K+1):
    if S-i-j>=0:
      points+=1
print(points)
