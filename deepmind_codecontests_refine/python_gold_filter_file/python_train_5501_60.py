n,m,k = map(int,input().split())

for i in range(m+1):
  for j in range(n+1):
    if j*(m-i)+i*(n-j)==k:
      print("Yes")
      exit()
      
print("No")