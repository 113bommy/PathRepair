import sys

def answer(n, k):
    dp = [[1 for j in range(n+1)] for i in range(k+1)]
    M = 10**9 + 7
    for i in range(1, k):
        for j in range(2, n+1):
            t = j
            while t <= n:
                dp[i+1][t] = dp[i+1][t] + dp[i][j]
                if dp[i+1][t] >= M:
                    dp[i+1][t] -= M
                t += j
    #print('dp=', dp)
    return sum(dp[k]) -1 #b/c row 0 is 1 and nonsense.

def main():
    n, k = map(int, sys.stdin.readline().split())
    print(answer(n, k))
    return
main()