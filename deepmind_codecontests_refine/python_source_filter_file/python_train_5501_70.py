N,M,K = map(int,input().split())

for n in range(N):
  for m in range(M):
    if K == m*N+n*M-2*(n*m):
      print('Yes')
      exit()
print('No')