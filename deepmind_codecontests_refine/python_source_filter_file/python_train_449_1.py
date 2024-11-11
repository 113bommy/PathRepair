def read():
    return [int(v) for v in input().split()]


def main():
    n = read()[0]
    t, c = [], []
    for i in range(n):
        line = read()
        t.append(line[0] + 1)
        c.append(line[1])

    MAX = 10 ** 15
    dp = [MAX] * (n + 1)
    dp[0] = 0
    for i in range(n):
        for j in range(n, -1, -1):
            dp[j] = min(dp[j], max(0, dp[j - t[i]] + c[i]))

    print(dp[n])


if __name__ == '__main__':
    main()
