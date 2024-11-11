n, d = map(int, input().split())
x = list(map(int, input().split()))
if 10 * (n - 1) + sum(x) >= d:
    print(-1)
else:
    print((d - sum(x)) // 5)
