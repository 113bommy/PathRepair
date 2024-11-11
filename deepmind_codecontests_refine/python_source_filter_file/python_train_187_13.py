N = int(input())
F = [int("".join(input().split()), 1) for i in range(N)]
P = [list(map(int, (input().split()))) for i in range(N)]

ans = float('-inf')
for bit in range(1,1024):
    sum_p = 0
    for shop in range(N):
        time = bin(F[shop] & bit).count('1')
        sum_p += P[shop][time]

    ans = max(sum_p, ans)
print(ans)
