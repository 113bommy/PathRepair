for _ in range(int(input())):
    n,m=map(int,input().split())
    b=[]
    i=1
    p=m
    while  (i*m)%10!=0:
        b.append(p%10)
        p+=m
        i+=1
    b.append(0)
    c1=n//m
    c2=c1//len(b)
    c3=c1%len(b)
    cost=0
    for i in range(len(b)-1):
        if i<c3:
            cost+=b[i]*(c2+1)
        else:
            cost+=b[i]*c2
    print(cost)