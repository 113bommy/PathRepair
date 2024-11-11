I=lambda:[int(i)for i in input().split()]
n,m=I()
P=I()
D={i:i for i in range(n)}
def U(x):
  if D[x]!=x:
    D[x]=U(D[x])
  return D[x]
for _ in [0]*m:
  x,y=I();D[U(x-1)]=U(y-1)
print(sum(U(i)==U(p-1)for i,p in enumerate(P)))


