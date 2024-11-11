import sys
sys.setrecursionlimit(10 ** 7)
inp = sys.stdin.buffer.readline


def resolve():
    MOD = 10 ** 9 + 7

    n = int(inp())
    e = [[] for _ in range(n)]
    for _ in range(n - 1):
        x, y = map(lambda x: int(x) - 1, inp().split())
        e[x].append(y)
        e[y].append(x)

    # dp[i][0]:i番目のノードが白のときの組み合わせの数
    # dp[i][1]:i番目のノードが黒のときの組み合わせの数
    dp = [[1, 1] for _ in range(n)]
    visited = [False for _ in range(n)]

    def dfs(vi, prnt):
        # if visited[vi]:
        #     return
        visited[vi] = True

        for chld in e[vi]:
            if chld == prnt or visited[chld]:
                continue
            dfs(chld, vi)

            # 親が白なら子は白でも黒でもいい
            dp[vi][0] *= (dp[chld][0] + dp[chld][1]) % MOD
            dp[vi][0] %= MOD
            # 親が黒田と子は白じゃないとダメ
            dp[vi][1] *= dp[chld][0] % MOD
            dp[vi][1] %= MOD

    dfs(0, -1)
    print((dp[0][0] + dp[0][1]) % MOD)


if __name__ == "__main__":
    resolve()
