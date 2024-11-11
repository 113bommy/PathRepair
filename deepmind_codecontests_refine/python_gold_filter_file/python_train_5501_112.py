n,m,k=map(int,input().split())
x='No'
for i in range(m+1):
  t=n*i
  if t==k:
    x='Yes'
    break
  for j in range(n):
    t+=m-2*i
    if t==k:
      x='Yes'
      break
print(x)