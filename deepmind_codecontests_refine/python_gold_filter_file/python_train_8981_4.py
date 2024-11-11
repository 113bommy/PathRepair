for i in range(int(input())):
    n,m = map(int,input().split())
    k = []
    for i in range(n):
        m = list(map(int,input().split()))
        k += m
    z = []
    p = []
    n = []
    for i in k:
        if i>0:
            p.append(i)
        elif i<0:
            n.append(abs(i))
        else:
            z.append(i)
    t = sum(p) + sum(n) + sum(z)
    if len(z) == 0:
        if len(n)%2 == 0:
            print(t)
        else:
            if len(p) == 0:
                print(t - 2*min(n))
            elif len(n) == 0:
                print( t - 2*min(p))
            else:
                print(t - 2*min(min(p),min(n)))
    else:
        print(t)