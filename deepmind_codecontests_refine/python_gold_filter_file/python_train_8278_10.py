def ok(m):
    k2 = k
    for i in range(n):
        o = (a[i] * m) - b[i]
        if o > 0:
            k2 -= o
    if k2 >= 0:
        return True
    return False


n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
l = 0
r = 2000000001
m = (r + l) // 2
while r - l > 1:
    if ok(m):
        l = m
    else:
        r = m
    m = ((r + l) // 2)
print(l)
