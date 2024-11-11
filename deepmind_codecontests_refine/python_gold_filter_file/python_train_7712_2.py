n=int(input()) 
a=list(map(int,input().split()))
if n<=1:
    print(0)
else:
        
    p1=0
    p2=n-1
    
    ap1=0
    ap2=0
    ap1+=a[p1]
    ap2+=a[p2]
    l=[]
    while True:
        
        if p1>=p2:
            break
        
        if ap1>ap2:
            p2-=1
            if p1>=p2:
                break
            ap2+=a[p2]
    
        elif ap2>ap1:
            p1+=1
            if p1>=p2:
                break
            ap1+=a[p1]
    
        elif ap1==ap2:
            l.append(ap1)
            
            p1+=1
            p2-=1
            if p1>=p2:
                break
            ap1+=a[p1]
            ap2+=a[p2]
           
            
    if ap1==ap2 :
        print(ap1)
    elif len(l)!=0:
        print(max(l))
    else:
        print(0)
    
    
        
    
     
    