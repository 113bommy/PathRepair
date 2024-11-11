def calc(v, k):
    res = 0
    for i in range(1000000000):
        temp = int(v / (k ** i))
        if temp == 0:
            break
        res += temp
    return res


n, k = map(int, input().split())
lo = 0
hi = 1
while calc(hi, k) < n:
    hi *= 2
while lo <= hi:
    mid = (lo + hi) // 2
    res = calc(mid, k)
    if res == n:
        break
    elif res < n:
        lo = mid + 1
    else:
        hi = mid - 1
lo = max(0, lo - 100)
res = None
for i in range(200):
    if calc(lo + i - 1, k) < n and calc(lo + i, k) >= n:
        res = lo + i
print(res)
