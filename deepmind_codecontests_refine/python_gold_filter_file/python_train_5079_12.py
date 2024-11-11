N, D, A = map(int, input().split())
XH = sorted([tuple(map(int, input().split())) for _ in range(N)])
ans, R, S = 0, 0, [0] * (N + 2)
for L in range(N):
    while R < N and XH[R][0] - XH[L][0] <= 2 * D:
        R += 1
    S[L + 1] += S[L]
    bomb = (max(XH[L][1] - S[L + 1], 0) + A - 1) // A
    ans += bomb
    S[L + 1] += bomb * A
    S[R + 1] -= bomb * A
print(ans)
