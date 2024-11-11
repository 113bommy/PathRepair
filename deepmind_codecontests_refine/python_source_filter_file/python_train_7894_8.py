###ncrのmodあまりの話
mod=10**9+7
N=100005
kaidan=[1 for i in range(N)]
gyaku=[1 for i in range(N)]
for i in range(1,N):
    kaidan[i] = (i * kaidan[i-1])%mod
    gyaku[i]=pow(bikkuri[i], mod-2, mod)
def comb(a,b):
    return kaidan[a]*gyaku[b]*gyaku[a-b]
n,m=map(int,input().split())
if abs(n-m)>=2:
    print(0)
else:
    if n==m:
        print(kaidan[n]*kaidan[n]*2%mod)
    else:
        a=max(n,m)
        b=min(n,m)
        print(kaidan[a]*kaidan[b]%mod)