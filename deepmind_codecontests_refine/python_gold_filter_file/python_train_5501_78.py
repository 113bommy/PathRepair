N,M,K=map(int,input().split())
for n in range(0,N+1):
  for m in range(0,M+1):
    if n*M+m*N-2*n*m==K:
      print("Yes")
      exit(0)
print("No")