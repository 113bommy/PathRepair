def modpow(a,n,p):
    if n==0:
        return 1
    x=modpow(a,n//2,p)
    x=(x*x)%p
    if (n%2)==1:
        x=(x*a)%p
    return x%p
def modinv(a,p):
    return modpow(a,p-2,p)
N,A,B,K=map(int,input().split())
p=998244353
fracmod=[1]*(N+1)
fracmodinv=[1]*(N+1)
ans=0
i=0
j=0
for i in range(1,N+1):
    fracmod[i]=(fracmod[i-1]*i)%p
#print(fracmod[:6])
for i in range(N+1):
    fracmodinv[i]=modinv(fracmod[i],p)
for i in range(N+1):
    forb=K-i*A      #bに割く得点
    if (forb%B==0)and(0<=(forb//B)<=N):
        j=forb//B
        #print(i,j)
        ans=(ans+((((fracmod[N]*fracmodinv[N-i]*fracmodinv[i])%p)*(fracmod[N]*fracmodinv[N-j]*fracmodinv[j]))%p))%p
print(ans)

