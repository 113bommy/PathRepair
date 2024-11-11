N, M, K = map(int, input().split())
  
for i in range(N+1):
  for j in range(M+1):
    if K == (N-i)*j + i*(M-j):
      print('Yes')
      exit()
      
print('No')