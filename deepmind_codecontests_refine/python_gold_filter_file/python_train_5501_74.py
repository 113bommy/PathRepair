N,M,K = map(int,input().split())

for n in range(N+1):
  for m in range(M+1):
    if K == m*N+n*M-2*(n*m):
      print('Yes')
      exit()
print('No')