n, m = map(int, input().split())
d = {0: 1}
asum = 0
ans = 0
for a in map(int, input().split()):
    asum = (asum + a) % m
    if asum in d:
        ans += d[asum]
        d[asum] += 1
    else:
        d[asum] = 1
print(ans