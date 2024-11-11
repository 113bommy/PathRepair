 = 998244353
n, m, k = map(int, input().split())
 
fact = [0]*(n+1)
fact[0] = 1
for i in range(1, n+1):
    fact[i] = fact[i-1]*i % MOD
 
invfact= [0]*(n+1)
for i in range(n+1):
    invfact[i] = pow(fact[i], MOD-2, MOD)
 
 
def nCk(n, k):
    return fact[n]*invfact[k]*invfact[n-k]
 
 
ans = 0
for i in range(k+1):
    ans += m*pow(m-1, n-1-i, MOD)*nCk(n-1, i)
    ans %= MOD
print(ans)