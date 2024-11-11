n=int(input())
eat=list(map(int,input().split()))
if n==1:
    print (1,end=" ")
    print (0)
    
elif n==2:
    print (1,end=" ")
    print (1)
    
else:
        
    l=0
    r=n-1
    ls=0
    rs=0
    while (l<r):
        if ls==rs:
            if r-l>1:
                ls+=eat[l]
                l+=1
                rs+=eat[r]
                r-=1
            else :
                ls+=eat[l]
                l+=1
        
        elif ls<rs:
            ls+=eat[l]
            l+=1
        elif rs<ls:
            rs+=eat[r]
            r-=1
            
    print (l,end=" ")
    print (n-l)