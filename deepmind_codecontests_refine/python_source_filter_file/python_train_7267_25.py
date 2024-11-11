import sys
input = sys.stdin.readline

def main():
    N = int(input())
    A = list(map(int, input().split()))

    dp = [[[0 for k in range(N + 1)]for j in range(N + 1)]for i in range(N + 1)]


    one = A.count(1)
    two = A.count(2)
    three = A.count(3)

    for k in range(three + 1):
        for j in range(two + three + 1 - k):
            for i in range(one + two + three + 1 -k -j):
                if i == 0 and j == 0 and k == 0:
                    continue
                ret = N
                if i > 0:
                    ret += dp[i - 1][j][k] * i
                if j > 0:
                    ret += dp[i + 1][j - 1][k] * j 
                if k > 0:
                    ret += dp[i][j + 1][k -1] * k

                dp[i][j][k] = ret / (i + j + k)

    print(dp[one][two][three])

main()
