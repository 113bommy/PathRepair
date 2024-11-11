MOD = 10**9+7
MAX = 2*10**5
n, m, k = map(int, input().split())

fact = [1]*(MAX+1)
for i in range(1, MAX+1):
    fact[i] = (fact[i-1]*i)%MOD
finv = [1]*MAX + [pow(fact[-1], MOD-2, MOD)]
for i in range(MAX, 0, -1):
    finv[i-1] = (finv[i]*i)%MOD

def comb(n, r):
    return ((fact[n]*finv[n-r])%MOD*finv[r])%MOD

cumsum = [0]*(MAX+1)
for i in range(1, max(n, m)+1):
    cumsum[i] = cumsum[i-1]+i

ans = 0
for i in range(n):
    ans += (cumsum[i] + cumsum[n-i-1])*(m**2)%MOD
for i in range(m):
    ans += (cumsum[i] + cumsum[m-i-1])*(n**2)%MOD

ans //= 2
ans = (ans*comb(n*m-2, k-2))%MOD
print(ans)
