n,k=map(int, input().split())
t=k
g=1
while t<n:
  t=t*k
  g+=1
print(g)
