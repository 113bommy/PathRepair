N, M, K = map(int, input().split())
  
for i in range(N):
  for j in range(M):
    if K == (N-i)*j + i*(M-j):
      print('Yes')
      exit()
      
print('No')