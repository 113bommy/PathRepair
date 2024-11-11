n, k = map(int, input().split())
a = list(map(int, input().split()))

hi = 10 ** 9
lo = 1
while hi - lo > 1:
    mid = (hi + lo) // 2

    cnt = 0
    for v in a:
        cnt += (v + mid - 1) // mid - 1

    if cnt <= k:
        hi = mid
    else:
        lo = mid

print(hi)