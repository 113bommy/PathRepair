n,m=map(int,input().split())
M,F=10**9+7,[1]
for i in range(m): F+=[-~i*F[i]%M]
c=lambda n,r: F[n]*pow(F[r]*F[n-r],M-2,M)
p=lambda n,r: F[n]*pow(F[n-r],M-2,M)
print(sum((-1)**k*c(n,k)*p(m,k)*p(m-k,n-k)**2 for k in range(n+1))%M)