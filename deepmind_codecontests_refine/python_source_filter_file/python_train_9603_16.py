for _ in range(int(input())):
    a,b,c,d=map(int,input().split())
    if a<=b:
        print(b)
    else:
        t1=a-b
        t2=c-d
        if t2<=0:
            print("-1")
            break
        if t1%t2==0:
            t3=t1//t2
        else:
            t3=t1//t2 +1
        print(b+c*t3)

