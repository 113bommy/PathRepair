N,Y=map(int,input().split())
for i in range(N+1):
  for k in range(N+1-i):
    m = N-i-k
    if 10000*i + 5000*k + 1000*m == Y:
      print(i,k,m)
      exit()
print(-1,-1,-1)