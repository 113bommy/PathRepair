for _ in range (int(input())):
    n=int(input())
    a=list()
    for i in range (n):
        s=input()
        a.append(s)
    #print(a)
    i=int(a[0][1]);j=int(a[1][0])
    c1=int(a[0][2])
    c2=int(a[1][1])
    c3=int(a[2][0])
    r=[]
    if i==j:
        if i==0:
            if c1==c2==c3==0:
                r.append((1,2))
                r.append((2,1))
            else:
                if c1==0:
                    r.append((1,3))
                if c2==0:
                    r.append((2,2))
                if c3==0:
                    r.append((3,1))
        else:
            if c1==c2==c3==1:
                r.append((1,2))
                r.append((2,1))
            else:
                if c1==0:
                    r.append((1,3))
                if c2==0:
                    r.append((2,2))
                if c3==0:
                    r.append((3,1))
    else:
        if i==1:
            if c1==c2==c3:
                if c1==1:
                    r.append((1,2))
                else:
                    r.append((2,1))
            else:
                if c1+c2+c3==1:
                    r.append((2,1))
                    if c1==1:
                        r.append((1,3))
                    elif c2==1:
                        r.append((2,2))
                    elif c3==1:
                        r.append((3,1))
                else:
                    r.append((1,2))
                    if c1==0:
                        r.append((1,3))
                    elif c2==0:
                        r.append((2,2))
                    elif c3==0:
                        r.append((3,1))
        else:
            if c1==c2==c3:
                if c1==1:
                    r.append((2,1))
                else:
                    r.append((1,2))
            else:
                if c1+c2+c3==1:
                    r.append((2,1))
                    if c1==1:
                        r.append((1,3))
                    elif c2==1:
                        r.append((2,2))
                    elif c3==1:
                        r.append((3,1))
                else:
                    r.append((2,1))
                    if c1==0:
                        r.append((1,3))
                    elif c2==0:
                        r.append((2,2))
                    elif c3==0:
                        r.append((3,1))
    print(len(r))
    for i in r:
        print(*i)