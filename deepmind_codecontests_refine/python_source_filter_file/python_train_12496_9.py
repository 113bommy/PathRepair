n, m, l = map(int, input().split())

A = [list(map(int,input().split())) for i in range(n)]

B = [list(map(int,input().split())) for i in range(m)]

C = [[0 for i in range(l)] for j in range(n)]

for i in range(0, n):
  for j in range(0, l):
    for k in range(0, m):
      C[i][j] = C[i][j] + A[i][k] * B[k][j] 

for i in range(0, n):
  print(*C[i])
print()    
