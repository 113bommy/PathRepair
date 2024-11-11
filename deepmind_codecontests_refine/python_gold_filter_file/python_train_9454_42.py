n=int(input())
for m in range(1,n+1):
  if m*(m+1)//2==n:break
else:
  print('No')
  exit()
a=[]
k=1
for i in range(m):
  b=[0]*m
  for j in range(i+1):
    b[j]=k
    k+=1
  a.append(b)
ans=[]
for i in range(m):
  b=[m]
  for j in range(i+1):
    b.append(a[i][j])
  for k in range(j+1,m):
    b.append(a[k][j])
  ans.append(b)
b=[m]
for i in range(m):
  b.append(a[i][i])
ans.append(b)
print('Yes')
print(len(ans))
for i in ans:
  print(*i)