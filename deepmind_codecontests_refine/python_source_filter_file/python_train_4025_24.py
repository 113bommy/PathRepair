from math import ceil
h, m = map(int, input().split())
hang, d, c, n, = map(int, input().split())
if 20 <= h <= 23:
    print(ceil(hang/n)*(c*0.8))

else:
    se = ceil(hang/n)*c
    t = (20-h-1) * 60 + 60 - m
    p = ceil(hang+d*t/n)*(c*0.8)
    if se < p:
        print('%.5f' % se)
    else:
        print('%.5f' % p)