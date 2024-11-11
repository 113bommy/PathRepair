def check(m1):
    for i in range(n):
        if i == 0:
            m1 -= (m + m1) / a[i]
            if m1 < 0:
                return 0
        elif i == n-1:
            m1 -= (m + m1) / b[i]
            if m1 < 0:
                return 0
        else:
            m1 -= (m + m1) / b[i]
            if m1 < 0:
                return 0
            m1 -= (m + m1) / a[i]
            if m1 < 0:
                return 0
    m1 -= (m + m1) / a[n - 1]
    if m1 < 0:
        return 0
    m1 -= (m + m1) / b[0]
    if m1 < 0:
        return 0
    return 1


n = int(input())
m = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
l = 0
r = 1e9+1
eps = 1e-6
while r - l > eps:
    med = (l + r) / 2
    if check(med):
        r = med
    else:
        l = med
if check(l):
    print(round(l, 6))
elif check(r):
    print(round(r, 6))
else:
    print(-1)