N, M, X = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

ans = 10**9 + 10

for i in range(N**2):
    money = 0
    L = [0] * M
    for j in range(N):
        if (i >> j) & 1:
            money += A[j][0]
            for k in range(M):
                L[k] += A[j][k+1]
    if min(L) >= X and money < ans:
        ans = money

if ans == 10**9 + 10:
    ans = -1

print(ans)