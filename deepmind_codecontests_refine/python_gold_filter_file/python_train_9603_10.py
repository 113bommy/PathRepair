for _ in range(int(input())):
    l=list(input().split(' '))
    a=int(l[0])
    b=int(l[1])
    c=int(l[2])
    d=int(l[3])
    if b>=a:
        print(b)
    elif c<=d:
        print(-1)
    else:
        if (a-b)%(c-d)==0:
            time=int(b+((a-b)//(c-d))*c)
            print(time)
        else:
            time=b+(int((a-b)/(c-d)))*c+c
            print(time)