for _ in range(int(input())):
    n,k=map(int,input().split())
    l1,r1=map(int,input().split())
    l2,r2=map(int,input().split())
    ans=0
    #intersection
    if max(l1,l2)<=min(r1,r2):   
        k-=(min(r1,r2)-max(l1,l2))*n
        if k<=0:
            print(0)
        else:
            add=((max(r1,r2)-min(l1,l2))-(min(r1,r2)-max(l1,l2)))
            # only by 1 we can do it
            if k-add*n<=0:
                print(k)
            # we have to use 2
            else:
                print(add*n+(k-add*n)*2)
    # no intersection
    else:
        ni = max(l1,l2)-min(r1,r2)
        bg=max(r1,r2)-min(l1,l2)
        for i in range(n):
            ans+=ni
            ans+=min(k,bg)
            k-=bg
            if k<=0:
                break
            if k*2<=ni:
                ans+=k*2
                k=-1
                break
        if k<=0:
            print(ans)
        else:
            print(ans+k*2)
            
            
        
        
        
        
        
        