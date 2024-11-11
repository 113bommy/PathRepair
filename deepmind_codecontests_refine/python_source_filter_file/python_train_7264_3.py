def main():
    mod = 998244353
    n = int(input())
    ab = [tuple(map(int, input().split())) for _ in [0]*n]
    ab.sort()
    next_a = [-1]*n
    dp = [0]*(n+1)
    dp[n] = 1
    for i in range(n-1, -1, -1):
        a0, b0 = ab[i]
        dist = a0+b0
        now = i
        while now < n-1:
            a1, b1 = ab[now+1]
            if a1 < dist:
                now = next_a[now+1]
            else:
                break
        next_a[i] = now
    for i in range(n-1, -1, -1):
        dp[i] = dp[i+1]+dp[next_a[i]+1] % mod
    print(dp[0])


main()