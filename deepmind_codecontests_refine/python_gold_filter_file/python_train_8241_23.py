q = int(input())
for i in range(q):
    n, m = map(int, input().split())
    ans = 0
    if m % 10 == 0:
        ans = 0
    elif m % 5 == 0:
        ans += n // (m * 2) * 5
        n -= (n // (m * 2)) * (m * 2)
        for j in range(0, n + 1, m):
            ans += j % 10
    elif m % 2 == 0:
        ans += n // (m * 5) * 20
        n -= (n // (m * 5)) * (m * 5)
        for j in range(0, n + 1, m):
            ans += j % 10
    else:
        ans += n // (m * 10) * 45
        n -= (n // (m * 10)) * (m * 10)
        for j in range(0, n + 1, m):
            ans += j % 10
    print(ans)
