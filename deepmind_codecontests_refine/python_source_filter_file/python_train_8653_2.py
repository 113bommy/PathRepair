n, s = map(int, input().split())
if not 2*n - 1 <= s <= n * (n+1) // 2:
    print('No')
    exit()
print('Yes')

def ok(d):
    dep, cur, sum, m = 2, 1, 1, 0
    while cur + m < n:
        m += cur
        cur = min(n - m, cur * d)
        sum += cur * dep
        dep += 1
    return sum <= s

l, r = 1, n
while l < r:
    mid = (l+r) // 2
    if ok(mid):
        r = mid
    else:
        l = mid + 1

a, me = [l-1] * (n+1), [_ for _ in range(n+1)]
sum, low = n * (n+1) // 2, 2
while n > low and sum > s:
    dest = min(sum-s, n-low)
    sum -= dest
    me[n] -= dest
    a[me[n]+1] += l
    a[me[n]] -= 1
    if not a[low]: low += 1
    n -= 1
me, l, dg = sorted(me[1:]), 1, 0
for i in me[1:]:
    while me[l] < i-1 or dg == r:
        dg = 0
        l += 1
    print(l, end=' ')
    dg += 1
