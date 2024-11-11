for _ in range(1):
    n,s=map(int,input().split())
    #l=[int(i) for i in input().split()]
    lo=1 
    hi=n 
    ans=n 
    while lo<=hi:
        mi=(lo+hi)>>1 
        curr=sum(int(i) for i in str(mi))
        if mi-curr>=s:
            hi=mi-1 
            ans=mi 
        else:
            lo=mi+1 
    print(n-ans+1)