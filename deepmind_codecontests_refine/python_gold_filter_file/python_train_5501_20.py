N,M,K=map(int,input().split())
for i in range(N+1):
  for j in range(M+1):
    B=i*M+j*N-i*j*2
    if B==K:
      print('Yes')
      exit()
print('No')