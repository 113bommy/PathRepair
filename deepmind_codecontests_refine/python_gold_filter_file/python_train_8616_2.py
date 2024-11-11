def comb_mod(n,r,mod):
    ans = 1
    lis = []
    for i in range(r):
        ans *= n+i
        ans *= pow(i+1,mod-2,mod)
        ans %= mod
        lis.append(ans)
    return lis
def solve():
    ans = 1
    mod = 10**9+7
    K = int(input())
    S = input()
    s = len(S)
    lis = comb_mod(s,K,mod)
    for k in range(K):
        ans *= 26
        ans += lis[k]*pow(25,k+1,mod)
        ans %= mod
    return ans
print(solve())