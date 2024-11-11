for _ in range(int(input())):
    a,b=map(int,input().split())
    if (abs(a-b)>=(b//2)):
        if b%2==0:
            print((b-1)%(b//2))
        else:
            print(b%((b+1)//2))
    else:
        print(b%a)
            