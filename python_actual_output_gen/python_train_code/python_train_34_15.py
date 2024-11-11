n,m = map(int,input().split())
P = [list(map(int,input().split())) for _ in range(n)]
C = [list(map(int,input().split())) for _ in range(m)]

for i in range(n):
  d = 9999
  t = 0
  for j in range(m):
    dist = abs(P[i][0]-C[j][0]) + abs(P[i][1]-C[j][1])
    if d > dist:
      t = j
      d = dist
  print(t+1)