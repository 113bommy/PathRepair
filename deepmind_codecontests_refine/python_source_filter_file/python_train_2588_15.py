from collections import defaultdict

h, w, n = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]

d = defaultdict(int)

for a, b in ab:
    for hi in range(a - 2, a + 1):
        for wi in range(b - 2, b + 1):
            if 1 <= hi <= h - 2 and 1 <= wi <= w - 2:
                d[(hi, wi)] += 1

cnt = [0] * 9
for v in d.values():
    cnt[v] += 1

cnt[0] = (h - 2) * (w - 2) - sum(cnt[1:])
print(*cnt, sep="\n")
