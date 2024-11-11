N,Y = map(int, input().split())
for i in range(N+1):
  for j in range(N+1-i):
    if Y==i*10000+j*5000+(N-i-j)*1000:
      print(i,j,(n-i-j))
      exit()
print('-1 -1 -1')