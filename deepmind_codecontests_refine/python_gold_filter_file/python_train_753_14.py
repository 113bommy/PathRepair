for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    l=list(map(int, input().split()))
    if k==0 or k==1 or k==2:
        for i in range(k):
            d=max(l)
            l=list(map(lambda x:d-x,l))
        print(*l)
    else:
        d=max(l)
        lk1=list(map(lambda x:d-x,l))
        d1=max(lk1)
        lk2=list(map(lambda x:d1-x,lk1))
        if k&1==0:
            print(*lk2)
        else:
            print(*lk1)
