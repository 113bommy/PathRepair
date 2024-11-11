import sys
sys.setrecursionlimit(100000000)
MOD = 10 ** 9 + 7

def main():
    K = input()
    D = int(input())

    dp = [[[0]*2 for _ in range(D)] for _ in range(len(K) + 1)] 
    dp[0][0][0] = 1
    for i in range(len(K)):
        M = int(K[i])
        for j in range(D):
            for k in range(10):
                if k < M:
                    dp[i + 1][(j + k)%D][1] += dp[i][j][1] + dp[i][j][0]
                elif k == M:
                    dp[i + 1][(j + k)%D][1] += dp[i][j][1]
                    dp[i + 1][(j + k)%D][0] += dp[i][j][0]
                else:
                    dp[i + 1][(j + k)%D][1] += dp[i][j][1]
                dp[i + 1][(j + k)%D][0] %= MOD
                dp[i + 1][(j + k)%D][1] %= MOD
    ans = sum(dp[-1][0])
    print((ans - 1)%MOD)       
if __name__ == '__main__':
    main()
    