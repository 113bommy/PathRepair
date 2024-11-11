for _ in range(int(input())):
    n=int(input())
    p,c=map(int,input().split())
    kk=0
    if p<c:
        kk=1
    
    for i in range(n-1):
        pp,cc=map(int,input().split())
        if pp<cc:
            kk=1
        if c<cc and p>=pp:
            kk=1
        if pp>=p and cc>=c:
            
            p=pp
            c=cc
            
        else:
            kk=1
    if kk==1:
        print("NO")
    else:
        print("YES")
    
    
        
    
        
               
