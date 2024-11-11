from itertools import accumulate

n, k = map(int, input().split())
p = [int(x) - 1 for x in input().split()]
c = list(map(int, input().split()))
ans = -(10 ** 18)

for i in range(n):
    pos = i
    scores = []
    while True:
        pos = p[pos]
        scores.append(c[pos])
        if pos == i:
            break
    m = len(scores)
    s = list(accumulate(scores))
    for j in range(m):
        x = (k - j - 1) // m
        ans = max(ans, s[j], s[j] + s[-1] * x)

print(ans)