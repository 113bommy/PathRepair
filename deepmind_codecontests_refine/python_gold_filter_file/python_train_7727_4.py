n = int(input())
mod = 998244353
psum = [0]*(n+3)
value = [0]*(n+2)
subs = [0]*(n+2)
for i in range(n, 0, -1):
    subs[i] = (subs[i+1] + psum[i+2] + 2*value[i+1])%mod
    value[i] = ((n-i+1) * pow(10, n-i+1, mod) - subs[i])%mod
    psum[i] = (psum[i+1] + value[i])%mod

print(*value[1:-1])