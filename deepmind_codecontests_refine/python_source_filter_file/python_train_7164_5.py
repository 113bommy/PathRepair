N, M , Q = map(int, input().split())

LR = [[0 for _ in range(N+2-i) for _ in range(N+2)]
for i in range(M):
  L, R = map(int, input().split())
  LR[L][R-L+1] += 1

  
for i in range(2,N+2):
  for j in range(1,N-i+2):
    LR[j][i] += LR[j][i-1] + LR[j+1][i-1] - LR[j+1][i-2]
    
for i in range(Q):
  p, q = map(int, input().split())
  print(LR[p][q-p+1]-LR[q+1][0])
