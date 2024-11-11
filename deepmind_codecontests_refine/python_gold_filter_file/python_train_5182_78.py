n, k = map(int, input().split())
p = list(map(int, input().split()))
c = list(map(int, input().split()))
for i in range(n):
    p[i] -= 1
ans = -float('inf')
for st in range(n):
    x = st
    score = []
    tot = 0
    while True:
        x = p[x]
        score.append(c[x])
        tot += c[x]
        if x == st:
            break
    l = len(score)
    now = 0
    t = 0
    for i in range(l):
        t += score[i]
        if i + 1 > k:
            break
        now = t
        if tot > 0:
            cycle_num = (k - (i + 1)) // l
            now += tot * cycle_num
        ans = max(ans, now)
print(ans)
