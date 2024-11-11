MOD = 998244353

def solve():
    n = int(input())
    ini = []
    out = []
    state = []
    for i in range(n):
        a, b, c = list(map(int, input().split()))
        ini.append(a)
        out.append(b)
        state.append(c)
    pos = []
    for a in out:
        le = 0
        ri = n-1
        while le < ri:
            mid = (le+ri) // 2
            if a > ini[mid]:
                le = mid + 1
            else:
                ri = mid
        pos.append(le)
    dp = [ini[0]-out[0]]
    for i in range(1, n):
        le = pos[i]
        a = (dp[i-1]+(ini[i]-ini[i-1])*2+ini[le]-out[i])%MOD
        if le:
            dp.append((a+dp[i-1]-dp[le-1]-ini[le]+ini[le-1])%MOD)
        else:
            dp.append((a+dp[i-1])%MOD)
    ans = ini[0]+1
    if state[0]:
        ans = (ans+dp[0])%MOD
    for i in range(1, n):
        if state[i]:
            ans = (ans+dp[i]-dp[i-1])%MOD
        else:
            ans = (ans+ini[i]-ini[i-1]) % MOD
    return ans



import sys
input = lambda: sys.stdin.readline().rstrip()
print(solve())

