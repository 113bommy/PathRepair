N, M, Q = map(int, input().split())
train = [[0]*(N+1) for _ in range(N+1)]

for i in range(M):
  a, b = map(int, input().split())
  train[a][b] += 1
  
for i in range(1, N+1):
  for j in range(1, N+1):
    train[i][j] += train[i][j-1]


for i in range(Q):
  ans = 0
  l, r = map(int, input().split())
  for j in range(l, r+1):
    ans += train[j][r]-train[j][l-1]
  print(ans)