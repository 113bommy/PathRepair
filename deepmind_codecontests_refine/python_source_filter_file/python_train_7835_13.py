for _ in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    s=sum(a)
    if s==0:
        print("No")
    else:
        b=[]
        sun=0
        sup=0
        for i in a:
            if i<0:
                sun+=i
            else:
                sup+=i
        if sup>abs(sun):
            for i in a:
                if i>0:
                    b.append(i)
            for i in a:
                if i<=0:
                    b.append(i)
        else:
            for i in a:
                if i<=0:
                    b.append(i)
            for i in a:
                if i>0:
                    b.append(i)
        print("Yes")
        print(*b)