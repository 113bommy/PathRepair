while True:
    try:
        a, b, c, d, e, f = map(int, input().split())
        tb, tc = d*b, d*c
        te, tf = a*e, a*f
        y = (tc-tf)//(tb-te)
        x = (c-(y*b))//a
        print("{:.3f} {:.3f}".format(x, y))

    except:
        return