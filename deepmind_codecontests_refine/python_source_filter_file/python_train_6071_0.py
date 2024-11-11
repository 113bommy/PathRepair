import sys
input = sys.stdin.readline

def main():
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))

    MX = int(1e5)
    primeFactors = [[] for _ in range(MX + 1)]
    for i in range(2, MX + 1):
        if len(primeFactors[i]) > 0:
            continue
        for j in range(i, MX + 1, i):
            primeFactors[j].append(i)
    
    MXH = 18
    nxt = [N for _ in range(MX + 1)]
    dp = [[N for _ in range(MXH + 1)] for __ in range(N + 1)]
    for i in range(N - 1, -1, -1):
        dp[i][0] = dp[i + 1][0]
        for factor in primeFactors[A[i]]:
            dp[i][0] = min(dp[i][0], nxt[factor])
            nxt[factor] = i

    for i in range(MXH + 1):
        for j in range(N):
            dp[j][i] = dp[dp[j][i - 1]][i - 1]

    for _ in range(Q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        cnt = 1
        for i in range(MXH, -1, -1):
            if dp[l][i] <= r:
                cnt += 1 << i
                l = dp[l][i]

        print(cnt)

main()