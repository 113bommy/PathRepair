n, y = map(int,input().split())

for i in range(n):
  for j in range(n-i):
    k = n-i-j
    if 10000*i + 5000*j + 1000*k == y:
      print(i,j,k)
      exit()
      
print("-1 -1 -1")
