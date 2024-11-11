n = int(input())


def calc(x):
    r = n
    ans = 0
    while r > 0:
        ans += min(x, r)
        r -= min(x, r)
        r -= r // 10
    return ans, n - ans


i, j = 1, n
while i + 1 < j:
    mid = (i + j) // 2
    a, b = calc(mid)
    if a < b:
        i = mid
    else:
        j = mid
print(j)
