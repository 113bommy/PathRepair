n, h = map(int, input().split())

def calc(mid):
    if mid <= h:
        return (1 + mid) * mid // 2
    peak = h - 1 + (mid - (h - 1) + 1) // 2
    if (mid - (h - 1)) % 2 == 0:
        return (h + peak) * (peak - h + 1) // 2 + (1 + peak) * peak // 2
    return (h + peak) * (peak - h + 1) // 2 + peak * (peak - 1) // 2

l, r = 0, h + 1
while r - l > 1:
    mid = (l + r) // 2
    if calc(mid) < n:
        l = mid
    else:
        r = mid
print(r)
