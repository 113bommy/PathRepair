n, m, d= map(int, input().split())
arr = (tuple(map(int, input().split())) for _ in range(n))
e = [x for r in arr for x in r]
e.sort()
for i in range(n * m - 1):
    if (e[i + 1] - e[i]) % d:
        print(-1)
        exit()
mid = n * m // 2
ans = 0
for i in e:
    ans += abs(i - e[mid]) // d
print(ans)