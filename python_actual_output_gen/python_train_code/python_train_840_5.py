while 1:
    try:
        a,b,c,d,e,f=[int(i) for i in input().split()]

        y=float((c*d-f*a)/(b*d-e*a))
        x=float((c-b*y)/a)
        print("{0:.4f}".format(x),"{0:.4f}".format(y))
    except EOFError:
        break