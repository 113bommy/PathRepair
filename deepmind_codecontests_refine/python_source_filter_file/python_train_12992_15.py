import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    MOD = 2**61-1
    SI = lambda : sys.stdin.readline().rstrip()

    s = SI()
    t = SI()
    lens = len(s)
    lent = len(t)

    def cx(x):
        return ord(x) - ord('a') + 1

    hsh = 0
    for x in t:
        hsh = (hsh * 26 + cx(x)) % MOD

    n = lens + lent * 2 
    dp = [0] * n

    h = 0
    ans = 0
    for i in range(n):
        if i >= lent:
            h -= cx(s[(i - lent)%lens]) * pow(26,lent-1,MOD)
        h = (h * 26 + cx(s[i % lens])) % MOD
        if h == hsh:
            if i < lent:
                dp[i] = 1
            else:
                dp[i] = dp[i-lent] + 1
            ans = max(ans,dp[i])

    if n - ans * lent < lent * 2 - 1:
        print(-1)
    else:
        print(ans)

if __name__ == '__main__':
    main()