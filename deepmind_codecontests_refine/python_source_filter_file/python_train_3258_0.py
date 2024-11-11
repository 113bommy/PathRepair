gans = []
for _ in range(int(input())):
    n, m = map(int, input().split())
    k = list(map(int, input().split()))
    c = list(map(int, input().split()))
    p = [0] * n
    k.sort()
    for i in range(n):
        p[i] = c[k[i] - 1]
    for i in range(1, n):
        p[i] += p[i - 1]
    for i in range(1, m):
        c[i] += c[i - 1]
    ans = p[-1]
    if m >= n:
        ans = min(ans, c[-1])
    for x in range(max(0, n - m - 1), n):
        cur = p[x] + c[n - x - 2]
        ans = min(ans, cur)
    gans.append(ans)
print('\n'.join(map(str, gans)))
