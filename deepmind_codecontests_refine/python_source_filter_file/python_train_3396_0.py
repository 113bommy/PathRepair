a,b,c,d=map(int,input().split())
x=b-c
f=1
if b<c or b<a-c or d>=2 and d<(a-c)*2 or d>=2 and b<c*2 :
    print(-1)
    exit()
k=0
for i in range(d) :
    if i+1==d :
        if f==1 :
            if x>=a-c :
                print(k)
            else :
                print(k+1)
        else :
            if x>=c :
                print(k)
            else :
                print(k+1)
        exit()
            
    if f==1 :
        
        if x>=(a-c)*2 :
            x=x-(a-c)*2
        
        else :
            x=b-(a-c)*2
            k=k+1
        f=2
    else :
        if x>=c*2 :
            x=x-c*2
        
        else :
            x=b-c*2
            k=k+1
        f=1
            
            
        
    
                
                
                
        
    
