N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]

ans = - 10**7

for i in range(1, 2**10):
    x = 0
    for n in range(N):
        c = 0
        for j in range(10):
            if (i >> j) & F[n][j]:
                c += 1
        x += P[n][c]
    ans = max(ans, x)

print(ans)