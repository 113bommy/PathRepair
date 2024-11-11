MOD = 10**9 + 7
K = int(input())
S = len(input())

FCT = [1]
for i in range(1, K+S+1):
    FCT.append((FCT[-1] * i)%MOD)

def pmu(n, r, mod=MOD):
    return (FCT[n] * pow(FCT[n-r], mod-2, mod)) % mod

def cmb(n, r, mod=MOD):
    return (pmu(n, r) * pow(FCT[r], mod-2, mod)) % mod

def solve():
    ans = 1
    for i in range(S+1, K+S+1):
        ans = (ans*26) % MOD
        add = pow(25, i-S, MOD)
        add = (add * cmb(i-1, i-S)) % MOD
        ans = (ans + add) % MOD
    return ans

if __name__ == "__main__":
    print(solve())
