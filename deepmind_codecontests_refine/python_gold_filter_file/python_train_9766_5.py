from collections import defaultdict
B,W = map(int,input().split())
mod = 10**9+7

fact = [0]*(10**6+1)
fact[0] = 1
for i in range(10**6):
    fact[i+1] = fact[i]*(i+1)%mod

def comb_(n,k):
    return fact[n]*pow(fact[k],mod-2,mod)*pow(fact[n-k],mod-2,mod)*pow(2,(n+1)*(mod-2),mod)%mod

f_B = defaultdict(lambda:pow(2,mod-2,mod))
f_W = defaultdict(lambda:pow(2,mod-2,mod))
g = defaultdict(lambda:pow(2,W*(mod-2),mod))

for i in range(B,B+W):
    f_B[i+1] = f_B[i]-comb_(i-1,B-1)*pow(2,mod-2,mod)
    f_B[i+1] %= mod

for i in range(W,B+W):
    f_W[i+1] = f_W[i]-comb_(i-1,W-1)*pow(2,mod-2,mod)
    f_W[i+1] %= mod

for i in range(W+1,B+W):
    g[i+1] = g[i] + comb_(i-1,W-1)
    g[i+1] %= mod

for i in range(1,B+W+1):
    if i < W+1:
        print(f_B[i])
    else:
        print((f_B[i]+f_W[i]+g[i]-pow(2,mod-2,mod))%mod)

