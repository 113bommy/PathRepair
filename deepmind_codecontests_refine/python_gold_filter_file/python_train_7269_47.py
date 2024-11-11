N,Y=map(int,input().split())
for i in range(N+1):
  for j in range(N-i+1):
    if Y==10000*i+5000*j+1000*(N-i-j):
      print("{} {} {}".format(i,j,N-i-j))
      exit()
print("-1 -1 -1")