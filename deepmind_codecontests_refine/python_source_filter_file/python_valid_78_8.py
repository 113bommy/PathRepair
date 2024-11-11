t = int(input(""))
l = []
if (t>=1 and t<=100000000):
    for i in range(t):
        a = 0
        b = 0
        c = 0
        
        p,q = map(int,input().split())
        if (p>=1 and q<= 1000000000 and p<=q):
            if ((q/2) > p):
                a = q/2
                b = int(a)+1
                c = q % b
                l.append(int(c))
            else:
                c = q%p
                l.append(c)
        else:
            break

    for i in l:
        print(i)

