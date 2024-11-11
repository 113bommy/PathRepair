n = int(input())

def can(k):
    cur = n
    s = 0
    while cur > 0:
        eat = min(k, cur)
        s += eat
        cur -= eat
        cur -= cur // 10
    return 2 * s >= n

left, right = 1, n
while left + 1 < right:
    mid = (left + right) >> 1
    if not can(mid):
        left = mid
    else:
        right = mid
print(right)