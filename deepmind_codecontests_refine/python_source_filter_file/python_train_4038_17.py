n, m, x = map(int, input().split())

A = [list(map(int, input().split())) for j in range(n)]
ans = 10 ** 6
for i in range(1 << n):
    s = [0] * (m + 1)
    for j in range(n):
        if i >> j & 1:
            for k in range(m+1):
                s[k] += A[j][k]
    if min(s[1:]) >= x:
        ans = min(ans, s[0])
print(-1) if ans == 10 **6 else print(ans)