n,m,c=map(int, input().split())
B=list(map(int, input().split()))
g=0
for i in range(n):
  A=list(map(int, input().split()))
  for i in range(m):
    t+=A[i]*B[i]
  if t+c>0:
    g+=1
  t=0
print(g)