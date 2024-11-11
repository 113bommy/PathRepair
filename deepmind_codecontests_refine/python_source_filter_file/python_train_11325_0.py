n, a, b = map(int,input().split())
mod = 10**9+7
total = pow(2, n, mod) - 1
def c(n, r):
    p, q = 1, 1
    for i in range(r):
        p *= (n-i)%mod
        q *= (i+1)%mod
    return p * pow(q, mod-2, mod)%mod

print((total - c(n, a) - c(n, b))%mod)