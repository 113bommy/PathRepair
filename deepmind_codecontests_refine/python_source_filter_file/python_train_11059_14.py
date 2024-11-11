for _ in range(int(input())):
    a=input()
    d=1
    dmax=1
    for i in a:
        if i=='L':
            d+=1
        else:
            if dmax<d:
                dmax=d
            d=1
    if d!=1:
       dmax=d
    print(dmax)
