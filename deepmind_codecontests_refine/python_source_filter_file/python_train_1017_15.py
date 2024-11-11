N, K, S = map(int, open(0).read().split())

fill = 10 ** 9 - 1 if S == 10 ** 9 else 10 ** 9
ans = [S] * K + [fill] * (N - K)
print(ans)
