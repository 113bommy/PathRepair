def main():
    N, T, *AB = map(int, open(0).read().split())

    dp = [0] * (T + max(AB[::2]))
    for w, v in sorted(zip(*[iter(AB)] * 2)):
        for i in reversed(range(T)):
            if dp[i + w] < dp[i] + v:
                dp[i + w] = dp[i] + v

    print(max(dp))

main()