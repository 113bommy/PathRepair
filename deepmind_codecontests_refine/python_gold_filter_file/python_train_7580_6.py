import sys
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def main():
    inf = 5000
    n = int(input()[:-1])
    # iより前に色cのj以上が何個あるかがcnts[c][i][j]
    cnts = [[[0] * (n + 1) for _ in range(2 * n + 1)] for __ in range(2)]
    pos = [[0] * n for _ in range(2)]
    for i in range(n * 2):
        c, a = input().split()
        c = (c == "W") * 1
        a = int(a) - 1
        pos[c][a] = i
        for cc in range(2):
            for j in range(n):
                if c == cc and a >= j:
                    cnts[cc][i + 1][j] = cnts[cc][i][j] + 1
                else:
                    cnts[cc][i + 1][j] = cnts[cc][i][j]
    #    for x in cnts:
    #        print(x)
    #    print(pos)

    dp = [[inf] * (n + 1) for _ in range(n + 1)]
    dp[0][0] = 0
    for w in range(1, n + 1):
        i = pos[1][w - 1]
        dp[0][w] = dp[0][w - 1] + cnts[0][i][0] + cnts[1][i][w - 1]
    for b in range(1, n + 1):
        i = pos[0][b - 1]
        dp[b][0] = dp[b - 1][0] + cnts[0][i][b - 1] + cnts[1][i][0]
    for b in range(1, n + 1):
        for w in range(1, n + 1):
            bi = pos[0][b - 1]
            wi = pos[1][w - 1]
            dp[b][w] = min(dp[b - 1][w] + cnts[0][bi][b - 1] + cnts[1][bi][w],
                           dp[b][w - 1] + cnts[0][wi][b] + cnts[1][wi][w - 1])
    print(dp[n][n])

main()
