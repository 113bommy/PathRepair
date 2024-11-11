from math import gcd

[n, m, q] = [int(x) for x in input().split()]


g = gcd(n,m)

for i in range(q):
    [s_x, s_y, e_x, e_y] = [int(x) for x in input().split()]
    s_y -= 1
    e_y -= 1
    if s_x == 1:
        sector_s = s_y // (n / g)
    else:
        sector_s = s_y // (m / g)

    if e_x == 1:
        sector_e = e_y//(n/g)
    else:
        sector_e = e_y//(m/g)


    print("YES" if sector_s == sector_e else "NO")

