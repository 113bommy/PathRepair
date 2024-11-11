N, C, K = map(int, input().split())
T = sorted([int(input()) for _ in range(N)])
ans = 0
i = 0
while i < N:
    p = 0
    lm = T[i] + K
    while i < N and p < C and lm > T[i]:
        p += 1
        i += 1
    ans += 1
print(ans)
