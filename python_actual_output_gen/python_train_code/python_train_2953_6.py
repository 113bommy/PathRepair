a=int(input())
if a>=0:
    print(a)
if a<0:
    a=str(a)
    a=' '.join(a)
    a=a.split()
    if a[-1]>=a[-2]:
        del a[-1]
        b=''
        for i in a:
            b=b+i
        b=int(b)
        if b==-0:
            b=b*(-1)
            print(b)
        else:
            print(b)
    if a[-1]<a[-2]:
        del a[-2]
        b=''
        for i in a:
            b=b+i
        b=int(b)
        if b==-0:
            b=b*(-1)
            print(b)
        else:
            print(b)
        
