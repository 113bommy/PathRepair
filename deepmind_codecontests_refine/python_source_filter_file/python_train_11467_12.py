import math

n, m = map(int, input().split())
a = list(map(int, input().split())) + [-1]
a.sort(reverse=True)
s = sum(a)

if m > s:
    print(-1)
    exit()

left, r = 0, n
while r - left > 1:
    mid = (left + r) // 2

    minus = 0
    i = 0
    ans = 0
    while a[i] > minus:
        cur = i
        while cur - i < mid:
            if a[cur] <= minus:
                minus = 999999999
                break
            ans += a[cur] - minus
            cur += 1
        i = cur
        minus += 1
    if ans >= m:
        r = mid
    else:
        left = mid
print(r)
