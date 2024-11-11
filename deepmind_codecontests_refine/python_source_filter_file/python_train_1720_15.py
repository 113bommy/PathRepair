n = int(input())

lo = 0
hi = 10 ** 7
while lo <= hi:
    mid = (lo + hi) // 2
    tmp = mid * (mid + 1) // 2
    if n > tmp:
        lo = mid + 1
    else:
        hi = mid - 1
# print(hi)
mult = hi * (hi + 1) // 2 + 1
print(n - mult + 1)
