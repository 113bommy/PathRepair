while True:
    try:
        a, b, c, d, e, f = map(int, input().split())
        tb, tc = d*b, d*c
        te, tf = a*e, a*f
        y = (tc-tf)//(tb-te)
        x = (c-(y*b))//a
        print("{0:.3f} {1:.3f}".format(x, y))

    except:
        break