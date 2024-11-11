N, M = map(int, input().split())
ans = 0

if N == M == 1:
    ans == 1
elif min(N, M) == 1:
    ans = max(N, M) - 2
else:
    ans = N * M - (N + M) * 2 + 4

print(ans)
