n,m=map(int,input().split())
a = 1
Mod=1e9+7
d = [1]*(n+1)
for i in range(n):
  d[i+1]=((m-n+i)*d[i]+i*d[i-1])%Mod
  a=a*(m-i)%Mod
print(int(a*d[n]%Mod))