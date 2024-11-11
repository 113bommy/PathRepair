q = int(input())
for _ in range(q):
    n, m = map(int, input().split())
    d = {}
    for i in range(m, m*10+1, m):
        d[i] = i%10
    sm = 0
    if n <= m*10:
        for i in range(m, n+1, m):
            sm += d[i]
        ans = sm
    else:
        for i in range(m, m*10+1, m):
            sm += d[i]
        res = n//(m*10)
        ans = res * sm
        for i in range(m*10*res+m, n, m):
            ans += i%10
    print(ans)