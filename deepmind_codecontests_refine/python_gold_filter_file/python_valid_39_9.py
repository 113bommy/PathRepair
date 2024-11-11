for _ in range(int(input())):
    #x = int(input())
    n, m = map(int, input().split())
    #A = list(map(int, input().split()))
    x1, y1, x2, y2 = map(int, input().split())
    a, b = map(int, input().split())
    if a + (x2 - x1) > n and b + (y2 - y1)  > m:
        print(-1)
    else:
        ans = 10 ** 40
        if a + (x2 - x1) <= n:
            ans = min(ans, max(0, a - x1), max(0, x2 - (n - a)))
        if b + (y2 - y1) <= m:
            ans = min(ans, max(0, b - y1), max(0, y2 - (m - b)))
        print(ans)