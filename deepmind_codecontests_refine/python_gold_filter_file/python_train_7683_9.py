n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

memo = [0] * (1 << n)
dp = [0] * (1 << n)

def f(s):
    if memo[s]:
        return dp[s]
    memo[s] = 1

    # 集合sを一つのグループとしたときに得られるスコア
    score = 0
    for i in range(n):
        for j in range(i+1, n):
            if ((s >> i) & 1) & ((s >> j) & 1):
                score += a[i][j]

    # sの部分集合でs自身と空集合を除いた集合を列挙(テクニックが存在)
    t = (s-1) & s   # s自身を除く (今回は関係ないがs自身を含む場合は t = s としてあげる)
    while t > 0:
        # 集合t と, 集合sから集合tを除いた集合に分けて、それぞれ再帰的にスコアを求める
        score = max(score, f(t) + f(s ^ t))
        t = (t-1) & s

    dp[s] = score
    return dp[s]

print(f((1 << n) - 1))