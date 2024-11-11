N, K = map(int, input().split())
mod = 10**9 + 7

def com(n, r):
    p, q = 1, 1
    for i in range(r):
        p = p*(n-i)%mod
        q = q*(r-i)%mod
    return p*pow(q, mod-2, mod)%mod

for k in range(1, K+1):
    print(com(N-K+1, k)*com(K-1, k-1)%mod)