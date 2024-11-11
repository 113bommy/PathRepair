N,M,Q = map(int,input().split())
LR = [[0 for _ in range(N)] for _ in range(N)]

for j in range(M):
  l,r = map(int,input().split())
  LR[l-1][r-1] += 1

for i in range(N):
  for j in range(1,N):
    LR[i][j] += LR[i][j-1]

for _ in range(Q):
  p,q = map(int,input().split())
  ans = 0
  for i in range(q-p+1):
    ans += LR[p+i-1][q-1]
  print(ans)