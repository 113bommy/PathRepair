N,K = map(int,input().split())
gcddic = {}
mod_n = (10**9+7)
for i in range(K,0,-1):
    x = pow((K//i),N)
    ll=2
    while(ll*i<=K):
        x -= gcddic[ll*(i)]
        ll += 1
    gcddic[i] = x
sumnation = 0
for i,l in gcddic.items():
    sumnation += i*l
print(sumnation%mod_n)