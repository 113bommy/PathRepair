N,M,K = map(int,input().split())

for n in range(N):
  for m in range(M):
    if n*(M-m) + m*(N-n) == K:
      print('Yes')
      exit()

print('No')
