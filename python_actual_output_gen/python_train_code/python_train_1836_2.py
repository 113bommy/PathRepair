eps = 0.000001


def check(x):
    temp_m = m + x
    for i in range(n):
        delta = temp_m / a[i]
        x -= delta
        temp_m -= delta
        if x < eps:
            return False
        delta = temp_m / b[(i + 1) % n]
        x -= delta
        temp_m -= delta
        if x < eps:
            return False
    return True


n = int(input())
m = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
l = 0
r = 1000000001
while r - l >= eps:
    mid = (r + l) / 2
    if check(mid):
        r = mid
    else:
        l = mid
if r == 1000000001:
    print(-1)
else:
    print(r)