N, C = map(int, input().split())
r = [[0] * C for _ in range(10 * 5)]
for _ in range(N):
    s, t, c = map(int, input().split())
    for i in range(s - 1, t):
        r[i][c - 1] = 1
ans = 0
for t in r:
    sum_t = sum(t)
    if sum_t > ans:
        ans = sum_t

print(ans)