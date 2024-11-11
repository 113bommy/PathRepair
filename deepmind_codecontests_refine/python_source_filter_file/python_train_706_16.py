def main():

    N, K = map(int, input().split())
    a = list(map(int, input().split()))
    dp = [[0]*(K+1) for i in range(N+1)]
    import collections
    dp[0][K] = 1
    mod = 10**9 + 7
    # dp[i][j] i人目まで配って、残りがj個の方法の数
    for i in range(1, N+1):
        tmp = 0
        q = collections.deque()
        for j in range(K, -1, -1):
            while(q):
                if q[0][0] > j:
                    t = q.popleft()
                    tmp -= t[1]
                else:
                    break
            if dp[i-1][j]:
                tmp += dp[i-1][j]
                q.append((max(j - a[i-1], 0), dp[i-1][j]))
            tmp %= mod
            dp[i][j] = tmp

    print(dp[-1][0])
main()
