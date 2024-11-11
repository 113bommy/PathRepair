for _ in range(int(input())):
    n,k=map(int,input().split())
    for i in range(k):
        mv=-99999
        miv=99999
        temp=n
        while n>0:
            rem=n%10
            mv=max(mv,rem)
            miv=min(miv,rem)
            n=n//10
        n=temp +mv*miv
        if miv==0:
            break
    print(n)
