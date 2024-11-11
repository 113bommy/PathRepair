def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())
INF = 10 ** 18

for t in range(ii()):
    n, x, y, d = mi()
    ans = INF
    if x % d == y % d:
        ans = min(ans, (y - x) // d)
    if 1 % d == y % d:
        ans = min(ans, (x - 1 + d - 1) // d + (y - 1) // d)
    if n % d == y % d:
        ans = min(ans, (n - x + d - 1) // d + (n - y) // d)
    print(-1 if ans == INF else ans)
