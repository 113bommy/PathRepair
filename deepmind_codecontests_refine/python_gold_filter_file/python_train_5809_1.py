import bisect
import copy

n, m = map(int,input().split())
a = list(map(int,input().split()))

a.sort()
asum = [0]
tmp = 0
for i in range(n):
    tmp += a[i] 
    asum.append(tmp)

lb = 1
ub = 2*10**5 + 1
while ub - lb > 1:
    cx = (ub+lb)//2
    cnt = 0
    total = 0
    for ca in a:
        cy = cx - ca
        ci = bisect.bisect_left(a, cy)
        cnt += n - ci
        total += asum[n] - asum[ci] + (n - ci) * ca
    if cnt >= m:
        lb = cx
        ans = copy.deepcopy(total) - (cnt - m) * cx
    else:
        ub = cx

print(ans)