n,k=map(int,input().split())
a,c=list(map(lambda x: int(x)-1,input().split())),0
for _ in range(60):
  if k%2:
    c=a[c]
  k//=2
  a=[a[a[i]]for i in range(n)]
print(c+1)