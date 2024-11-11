n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
X=0;Y=0
mod=10**9+7
for i in range(n-1):
  X+=(a[i+1]-a[i])*(i+1)*(n-i-1)
  X%=mod
for i in range(m-1):
  Y+=(b[i+1]-b[i])*(i+1)*(m-i-1)
  Y%=mod
print((X*Y)%mod)
