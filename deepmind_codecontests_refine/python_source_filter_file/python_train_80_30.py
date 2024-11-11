n,m=map(int,input().split())
x=[int(input()) for _ in range(m)]
f=[0]*(n+1)
f[0]=1
for i in range(1,n+1):
  f[i]=(f[i-1]+f[i-2])%(10**9+7)
  if i in x:
    f[i]=0
print(f[n]%(10**9+7))