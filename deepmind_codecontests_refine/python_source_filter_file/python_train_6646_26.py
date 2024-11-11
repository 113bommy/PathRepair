import collections
n,m=map(int,input().split())
A=[]
for i in range(n):
  A.append([int(_) for _ in input().split()])
D=dict()
for i in range(m):
  D[i+1]=1
ans=n
for _ in range(m):
  p=[]
  for i in range(n):
    for j in range(m):
      if D[A[i][j]]==1:
        p.append(A[i][j])
        break
  pp=collections.Counter(p).most_common()
  a,b=pp[0]
  ans=min(ans,b)
  D[a]=0
print(ans)