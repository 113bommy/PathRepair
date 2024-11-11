n,m,k = list(map(int,input().split()))


def alt(n,m,k,pat,buff):
    if k==0:
        return 0
    l = (m-1)*3
    if l<=k:
        buff.append((m-1,pat))
        k = k-l
    else:
        if k//3>0:
            buff.append(((k//3),pat))
        k = k%3
        if k == 1:
            buff.append((1, pat[:1]))
        elif k==2:
            buff.append((1, pat[:2]))
        k = 0
    return k

def state1(n,m,k,first,second,buff):
    if k==0:
        return 0
    if k>=m-1:
        buff.append((m-1,first))
        k-=(m-1)
    else:
        buff.append((k,first))
        return 0
    if k==0:
        return 0
    if k>=m-1:
        buff.append((m-1,second))
        k-=(m-1)
    else:
        buff.append((k,second))
        return 0
    return k  

def state2(n,m,k,direction,buff):
    if k==0:
        return 0
    if k>=m-1:
        buff.append((m-1,direction))
        k-=(m-1)
    else:
        buff.append((k, direction))
        return 0
    return k

if k>4*n*m-2*n-2*m:
    print("NO")
else:
    buff = []
    print("YES")
    if n == 1:
        buff.append((min(k,m-1),"R"))
        k-=(m-1)
        if k>0:
            buff.append((k, "L"))
    elif m == 1:
        buff.append((min(k,n-1),"D"))
        k-=(n-1)
        if k>0:
            buff.append((k,"R"))

    else:
        state = 0
        y = 0
        while k>0:
            if state == 0:
                if y == n-1:
                    state=1
                    continue
                if y%2 == 0:
                    k = alt(n,m,k,"DUR",buff)
                else:
                    k = alt(n,m,k,"DUL",buff)
                if k>0:
                    buff.append((1, "D"))
                    k-=1
                y+=1
            elif state == 1:
                if y%2==0:
                    k=state1(n,m,k,"R","L",buff)
                else:
                    k=state1(n,m,k,"L","R",buff)
                state = 2
            elif state == 2:
                buff.append((1,"U"))
                k-=1
                if y%2==0:
                    k = state2(n,m,k,"R",buff)
                else:
                    k = state2(n,m,k,"L",buff)
                y-=1
    print(len(buff))
    for x in buff:
        print(x[0],x[1])






