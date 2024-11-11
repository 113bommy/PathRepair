n, m, v, p = map(int, input().split())
a = list(map(int, input().split()))

a.sort(reverse=True)


def can_be_used(x):
    # x: 0-index
    if x < p:
        return True

    if a[x] + m < a[p-1]:
        return False

    vote_max = (p - 1 + n - x) * m
    for i in range(p-1, x):
        vote_max += a[x] + m - a[i]

    if vote_max < m * v:
        return False

    return True


l = 0
r = n

while r - l > 1:
    mid = (l + r) // 2

    if can_be_used(mid):
        l = mid
    else:
        r = mid

ans = l + 1
print(ans)
