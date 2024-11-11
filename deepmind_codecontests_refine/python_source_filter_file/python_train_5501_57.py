n,m,k=map(int,input().split())
a='No'
for i in range(n):
  for j in range(m):
    if j*(n-i)+i*(m-j)==k:
      a='Yes'
      break
print(a)