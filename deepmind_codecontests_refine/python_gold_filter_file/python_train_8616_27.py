def solve():
    K = int(input())
    S = input()
    N = len(S)

    MOD = 10**9+7
    n = N+K
    fac = [1]*(n+1)
    rev = [1]*(n+1)
    
    for i in range(1,n+1):
        fac[i] = i*fac[i-1]%MOD
        rev[i] = pow(fac[i], MOD-2, MOD)
    
    comb = lambda a,b:(fac[a]*rev[a-b]*rev[b])%MOD

    ans = 0
    for i in range(K+1):
        ans += pow(26, K-i, MOD) * pow(25, i, MOD) * comb(N+i-1, i)
        ans %= MOD
    print(ans)


solve()
