import collections, math
t = int(input())
for _ in range(t):
    n = int(input())
    cnt = collections.defaultdict(int)
    for _ in range(n):
        x, y, u, v = map(int, input().split())
        du, dv = u - x, v - y
        g = math.gcd(du, dv)
        cnt[(du // g, dv // g)] += 1

    ans = 0
    for du, dv in tuple(cnt.keys()):
        ans += cnt[(du, dv)] * cnt[(-du, -dv)]
        cnt[(du, dv)] = 0
        cnt[(-du, -dv)] = 0
    
    print(ans)
