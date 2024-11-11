n,m,k = map(int,input().split())

for i in range(m):
  for j in range(n):
    if j*(m-i)+i*(n-j)==k:
      print("Yes")
      exit()
      
print("No")