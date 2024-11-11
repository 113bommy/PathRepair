K=int(input())
S=input()
N=len(S)
mod=10**9+7

fact=[0]*(K+N)
fact[0]=fact[1]=1
for i in range(2,K+N):
    fact[i]=fact[i-1]*i%mod

def comb(n,r):
    ret=fact[n]*pow(fact[r],-1,mod)*pow(fact[n-r],-1,mod)%mod
    return ret

ans=0
for i in range(K+1):
    ans+=pow(26,i,mod)*pow(25,K-i,mod)*comb(K+N-1-i,N-1)
    ans%=mod

print(ans)