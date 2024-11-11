n,m,x=map(int,input().split())
c=[list(map(int,input().split())) for _ in range(n)]
result=-1
for i in range(2**n):
  t=[0]*m
  money=0
  for j in range(n):
    if (i>>j)&1==0:
      continue
    money+=c[j][0]
    for k in range(1,m):
      t[k]+=c[j][k]
  if all(xx>=x for xx in t):
    if result==-1:
      result=money
    else:
      result=min(result,money)
print(result)