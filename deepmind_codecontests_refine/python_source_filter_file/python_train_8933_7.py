mod = 998244353
N, A, B, K = map(int, input().split())
def make_fact(n):#0~nの階乗を求める
    fact = [1]*(n+1)
    for i in range(1, n+1):
        fact[i] = fact[i-1]*i%mod
    return fact
fact = make_fact(N) #＠
def make_fact_inv(n):#0~nの階乗のmodに関する逆元を求める
    fact_inv = [1]*(n+1)
    fact_inv[n] = pow(fact[n], mod-2, mod)#フェルマーの小定理
    for i in range(n, 0, -1):
        fact_inv[i-1] = fact_inv[i]*i%mod
    return fact_inv
fact_inv = make_fact_inv(N)#＠
def comb(n, k):#nCk
    return fact[n]*fact_inv[k]*fact_inv[n-k]%mod
ans = 0
for k in range(N+1):
    r = K-k*A
    if r%B != 0 or r//B>N:
        continue
    l = r//B
    ans+=comb(N, k)*comb(N, l)
    ans%=mod
print(ans)

