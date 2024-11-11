n,m=map(int,input().split())
M,F=10**9+7,[1]
for i in range(m): F+=[-~i*F[i]%M]
c=lambda n,r: F[n]*pow(F[r]*F[n-r],-1,M)
p=lambda n,r: F[n]*pow(F[n-r],-1,M)
print(sum((-1)**k*c(n,k)*p(m,k)*p(m-k,n-k)**2 for k in range(n+1))%M)