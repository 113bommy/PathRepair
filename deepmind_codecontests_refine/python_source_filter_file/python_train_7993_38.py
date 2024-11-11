#D
X,Y=map(int,input().split())
mod=10**9+7
N=10**6

fact=[1 for i in range(N+1)]
for i in range(1,N):
    fact[i+1]=(fact[i]*(i+1))%mod

def nCk(n,k):
    return fact[n]*pow(fact[n-k]*fact[k],mod-2,mod)

ans=0
if (2*Y-X)%3==0 and (2*X-Y)%3==0 and (2*Y-X)>0 and (2*X-Y)>0:
    cntx=(2*Y-X)//3
    cnty=(2*X-Y)//3
    
    ans=nCk(cntx+cnty,cntx)%mod

print(ans)