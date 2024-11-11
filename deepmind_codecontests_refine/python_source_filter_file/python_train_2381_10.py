while True:
    try:
        a, b, c, d, e, f = map(float, input().split())
        x = (c*e - b*f)/(a*e - b*d)
        y = (a*f - c*d)/(a*e - b*d)
        print("{:.3f} {:.3f}".format(x, y))
    except:
        break
