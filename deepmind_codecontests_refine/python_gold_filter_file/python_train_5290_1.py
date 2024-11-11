from bisect import bisect
from operator import itemgetter

n, a, b = map(int, input().split())
ppp = map(int, input().split())
qqq = [i for i, p in sorted(enumerate(ppp, start=1), key=itemgetter(1))]
INF = 10 ** 15

dp = [(0, 0)]
for i in qqq:
    ndp = []
    s = bisect(dp, (i,))
    tmp_min = INF
    for j, cost in dp[:s]:
        cost += b
        ndp.append((j, cost))
        tmp_min = cost
    stay_cost = dp[s - 1][1]
    if tmp_min > stay_cost:
        ndp.append((i, stay_cost))
        tmp_min = stay_cost
    for j, cost in dp[s:]:
        cost += a
        if tmp_min > cost:
            ndp.append((j, cost))
            tmp_min = cost
    dp = ndp

print(dp[-1][1])
