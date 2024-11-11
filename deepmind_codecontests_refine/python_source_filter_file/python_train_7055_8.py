M=10**9+7
n,m=map(int,input().split())
F=[1]
for i in range(1,m+1): F+=[i*F[-1]%M]
c=lambda n,r: F[n]*pow(F[r]*F[n-r],-1,M)%M
p=lambda n,r: F[n]*pow(F[n-r],-1,M)%M
a=0
for k in range(n+1):
  a+=(-1)**k*c(n,k)*p(m,k)*p(m-k,n-k)**2%M
print(a%M)