for _ in range(1):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    mid=l[n//2]
    
    c=0
    if k>mid:
        for x in range(n//2,n):
            if k>l[x]:
                c=c+(k-l[x])
            else:
                break
    else:
        for x in range(0,n//2):
            if k<l[x]:
                c=c+(l[x]-k)
                
    print(c)            
    
    
            
        