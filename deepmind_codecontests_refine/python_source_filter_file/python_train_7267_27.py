from collections import Counter

def solve():
    N = int(input())
    As = list(map(int, input().split()))

    cnt = Counter(As)

    dp = [[[0]*(N+1) for j in range(N+1)] for i in range(N+1)]
    for k in range(N+1):
        for j in range(N+1):
            if j+k > N:
                break
            for i in range(N+1):
                if i+j+k > N:
                    break
                expe = 0.0
                if i > 0:
                    expe += i/N * dp[i-1][j][k]
                if j > 0:
                    expe += j/N * dp[i+1][j-1][k]
                if k > 0:
                    expe += k/N * dp[i][j+1][k-1]
                if i+j+k:
                    expe = (expe+1)*N/(i+j+k)
                dp[i][j][k] = expe

    ans = dp[cnt[1]][cnt[2]][cnt[3]]
    print(ans)


solve()
