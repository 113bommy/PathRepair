N, K, S = map(int, input().split())
if S == 1:
    tmp = 2
else:
    tmp = 1

ans = [S] * K + [tmp] * (N-K)
print(*ans)
