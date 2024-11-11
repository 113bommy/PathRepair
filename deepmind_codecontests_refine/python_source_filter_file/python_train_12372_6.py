from copy import copy
n = int(input())
INF = 10**12

A = []
for i in range(n):
  A.append(list(map(int,input().split())))

B = [[1]*n for _ in range(n)]
G = copy(A)

for k in range(n):
  for i in range(n):
    for j in range(n):
      G[i][j] = min(G[i][j], G[i][k]+G[k][j])
      if not (i==j or j==k or k==i):
        if G[i][j] == G[i][k]+G[k][j]:
          B[i][j] = 0
      
if A==G:
  ans = 0
  for i in range(n):
    for j in range(i+1,n):      
      ans += G[i][j] * B[i][j]
  print(ans)
else:
  print(-1)