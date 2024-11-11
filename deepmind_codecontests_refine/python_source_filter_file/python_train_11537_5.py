import bisect
inf = 10**18
a, b, q = map(int, input().split())
s = [-inf] + [int(input()) for _ in range(a)] + [inf]
t = [-inf] + [int(input()) for _ in range(a)] + [inf]

for _ in range(q):
    x = int(input())
    i = bisect.bisect_right(s, x)
    j = bisect.bisect_right(t, x)
    ans = inf
    for s_x in [s[i-1], s[i]]:
        for t_x in [t[i-1], t[i]]:
            ans0 = abs(s_x - x) + abs(t_x - s_x)
            ans1 = abs(t_x - x) + abs(s_x - t_x)
            ans = min(ans, ans0, ans1)
    print(ans)
