import copy
def right(a):
    d = a[1] - a[0]
    res, f = 0, True
    for i in range(2, len(a)):
        if a[i] - a[i - 1] == d + 1:
            a[i] -= 1
            res += 1
        elif a[i] - a[i - 1] == d - 1:
            a[i] += 1
            res += 1
        elif a[i] - a[i - 1] != d:
            f = False
            break
    if not f:
        res = 10 ** 9
    return res
n = int(input())
bs = list(map(int, input().split()))
if n <= 2:
    print(0)
else:
    f = n + 1
    bs[0] -= 1
    bs[1] -= 1
    f = min(f, right(bs.copy()) + 2)
    bs[1] += 1
    f = min(f, right(bs.copy()) + 1)
    bs[1] += 1
    f = min(f, right(bs.copy()) + 2)
    bs[0] += 1
    bs[1] -= 2
    f = min(f, right(bs.copy()) + 1)
    bs[1] += 1
    f = min(f, right(bs.copy()))
    bs[1] += 1
    f = min(f, right(bs.copy()) + 1)
    bs[0] += 1
    bs[1] -= 2
    f = min(f, right(bs.copy()) + 2)
    bs[1] += 1
    f = min(f, right(bs.copy()) + 1)
    bs[1] += 1
    f = min(f, right(bs.copy()) + 1)
    if f == n + 1:
        f = -1
    print(f)