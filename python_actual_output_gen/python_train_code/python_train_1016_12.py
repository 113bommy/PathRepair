N = int(input())
S = [input() for _ in range(N)]
ans = 0
for k in range(N):
    f = True
    for i in range(N):
        for j in range(i + 1, N):
            if S[i][(j + k) % N] != S[(j + k) % N][i]:
                f = False
                break

        if not f:
            break
    if f:
        ans += N
print(ans)