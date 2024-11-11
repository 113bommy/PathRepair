from fractions import gcd
while True:
    a = list(map(int, input().split()))
    if a.count(0) == 6:
        break
    x = a[0] % a[1]
    ix = 1
    while x != 1:
        x = a[0] * x % a[1]
        ix += 1
    y = a[2] % a[3]
    iy = 1
    while y != 1:
        y = a[2] * y % a[3]
        iy += 1
    z = a[4] % a[5]
    iz = 1
    while z != 1:
        z = a[4] * z % a[5]
        iz += 1
    ixy = ix * iy // gcd(ix, iy)
    print(ixy * iz // gcd(ixy, iz))