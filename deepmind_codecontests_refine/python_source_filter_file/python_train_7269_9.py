N,Y = map(int,input().split())
for i in range(1,N+1):
  for j in range(1,N-i+1):
    k = N-i-j
    if i*10000 + j*5000 + k*1000 == Y:
      print(i,j,k)
      exit()
print("-1 -1 -1")
