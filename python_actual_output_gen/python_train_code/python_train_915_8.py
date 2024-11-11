for i in int(input())*[0]:
    a,b=map(int,input().split())
    if b>a:
        c=b//a
        d=b%a
        l=[c]*a
        i=0
        while d!=0:
            l[i]+=1
            d-=1
            i+=1
            if i>len(l)-1:
                i=0
        print(sum(i*i for i in l))
    else:
        print(b**2)