import sys

def trade(n, a, b):
    a0, a1, a2 = a
    b0, b1, b2 = b
    dp = [0] * (n+1)
    for i i range(1, n+1):
        gold, silver, copper = 0, 0, 0
        if i >= a0:
            gold = dp[i-a0] + b0
        if i >= a1:
            silver = dp[i-a1] + b1
        if i >= a2:
            copper = dp[i-a2] + b2
        dp[i] = max(i, gold, silver, copper)

    return dp[n]


def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    # Trade A -> B
    M = trade(N, A, B)
    # Trade B -> A
    return trade(M, B, A)


if __name__ == '__main__':
    print(main())
