from operator import itemgetter


n, x, d = map(int, input().split())

a = [0] * n
for i in range(n - 1):
    a[i + 1] = a[i] + 1

ruiseki1 = [0] * (n + 1)
ruiseki2 = [0] * (n + 1)

for i in range(n):
    ruiseki1[i + 1] += ruiseki1[i] + a[i] 
for i in range(n):
    ruiseki2[i + 1] += ruiseki2[i] + a[n - i - 1] 

if d == 0 and x == 0:
    print(1)
    exit()
elif d == 0:
    print(n + 1)
    exit()
    
memo = {}

for i in range(n + 1):
    s_cnt = i
    geta = i * x
    div = geta // d
    mod = geta % d
    min_ = ruiseki1[i]
    max_ = ruiseki2[i]
    if mod not in memo:
        memo[mod] = []
    memo[mod].append((min_ + div, max_ + div + 1))

ans = 0
for i in memo:
    memo[i] = sorted(memo[i])
    r_max = -10**18
    for j in memo[i]:
        l, r = j
        if r - r_max < 0:
            continue
        ans += min(r - l, r - r_max)
        r_max = r
print(ans)
