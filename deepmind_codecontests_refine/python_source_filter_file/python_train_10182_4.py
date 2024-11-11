def main():
    N = int(input())
    a = tuple(map(int, input().split()))
    b = tuple(map(int, input().split()))

    # 1 周目 : dp[巣から持ってきたドングリ数] = 取引所 B で持てる最大ドングリ数
    dp = list(range(N + 1))
    mas = tuple(zip(a, b))
    for i in range(N + 1):
        for to_metal, to_acorn in mas:
            if i >= to_metal:
                dp[i] = max(dp[i], dp[i - to_metal] + to_acorn)
    N = dp[N]

    # 2 周目 : dp[取引所 B から持ってきたドングリ数] = 巣に持ち帰れる最大ドングリ数
    dp = list(range(N + 1))
    mas = tuple(zip(b, a))
    for i in range(N + 1):
        for to_metal, to_acorn in mas:
            if i >= to_metal:
                dp[i] = max(dp[i], dp[i - to_metal] + to_acorn)
    print(N)


if __name__ == '__main__':
    main()
