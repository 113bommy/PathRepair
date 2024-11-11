N,M,K=map(int,input().split())
MOD=10**9+7
ans=0
x,y=1,1
k=min(K-2,N*M-K)
for i in range(k):
    x*=N*M-2-i
    y*=k-i
    x%=MOD
    y%=MOD
comb=x*pow(y,MOD-2,MOD)
comb%=MOD
for i in range(1,N):
    a=i*comb*(N-i)*M**2
    ans+=a
    ans%=MOD
for i in range(1,M):
    a=i*comb*(M-i)*N**2
    ans+=a
    ans%=MOD
print(ans%MOD)