n,m,k=map(int,input().split())
a='No'
for i in range(n+1):
  for j in range(m+1):
    if j*(n-i)+i*(m-j)==k:
      a='Yes'
      break
print(a)