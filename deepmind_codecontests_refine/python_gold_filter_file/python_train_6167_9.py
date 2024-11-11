for _ in range(int(input())):
    n=int(input())
    t=input()
    s=t[1:]
    a="1"
    b="1"
    f=False
    for i in s:
        if i=='2':
            if not f:
                a+='1'
                b+='1'
            else:
                a+='2'
                b+='0'
        elif i=='0':
            a+='0'
            b+='0'
        elif i=='1':
            a+='1'
            b+='0'
            if not f:
                a,b=b,a
                f=True
                
    print(a)
    print(b)
