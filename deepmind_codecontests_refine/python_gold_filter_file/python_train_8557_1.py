n, k = map(int, input().split())

left = 0
right = 10**18 + 2

#print("started")

p = [2**i for i in range(61)]

while right - left > 2:
    #print(left, right)
    mid = (right + left) // 2
    mid -= mid % 2
    l = 0
    r = 60
    if mid > n:
        right = mid
        continue
    while r - l > 1:
        m = (r + l) // 2
        if mid * p[m] <= n:
            l = m
        else:
            r = m
    cur = 0
    cur += p[l + 1] - 2 + min(n - p[l] * mid + 1, p[l + 1])
    if cur < k:
        right = mid
    else:
        left = mid

x = left

#print("finished 1")

left = 1
right = 10 ** 18 + 1

while right - left > 2:
    #print(left, right)
    mid = (right + left) // 2
    if mid % 2 == 0:
        mid += 1
    l = 0
    r = 60
    if mid > n:
        right = mid
        continue
    while r - l > 1:
        m = (r + l) // 2
        if mid * p[m] <= n:
            l = m
        else:
            r = m
    cur = 0
    cur += min(n - p[l] * mid + 1, p[l]) + p[l] - 1
    if cur < k:
        right = mid
    else:
        left = mid

#print("finished 2")

print(max(left, x))
