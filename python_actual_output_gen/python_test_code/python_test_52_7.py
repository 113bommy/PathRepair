for i in range(int(input())):
    n=int(input())
    b=list(map(int,input().split()))
    l=0
    r=n-1
    c=[0]
    d=0
    while l<=r:
        if b[l]<=b[r]:
            if b[l]>=c[len(c)-1]:
                c.append(b[l])
                l=l+1
            else:
                c=[0]
                d=l
                r=n-1
        else:
            if b[r]>=c[len(c)-1]:
                c.append(b[r])
                r=r-1
            else:
                c=[0]
                l=r
                r=n-1
                d=l
    print(d)
            
            
                    
        
     
                
    
                  
            
