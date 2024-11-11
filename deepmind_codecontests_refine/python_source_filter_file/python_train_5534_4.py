import sys


def check(s, st, n):
    sum = (st * 2 + (n - 1)) * n // 2
    return s >= sum


m, n = map(int, input().split())

a = [0] * n
last = 0
for i in range(n):
    le = last + 1
    if i == 0:
        ri = m
    else:
        ri = last * 2 + 1
    while ri - le > 1:
        mid = (le + ri) // 2
        if check(m, mid, n - i):
            le = mid
        else:
            ri = mid

    if not check(m, le, n - i):
        print('NO')
        sys.exit()
    a[i] = le
    m -= le
    last = le
if m == 0:
    print('YES')
    print(*a)
else:
    print('NO')
