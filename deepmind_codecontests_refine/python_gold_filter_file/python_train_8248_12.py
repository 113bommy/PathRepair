t=int(input())
for ab in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    kx=set()
    for al in a:
        kx.add(al)
    
    ts=True
    for px in range(1,1024):
        ux=set()
        count=0
        for tl in a:
            if ((tl^px) in kx and (tl^px) not in ux):
                ux.add(tl^px)
            else:
                break
            count+=1
        if (ux==kx and count==len(a)):
            print(px)
            ts=False
            break
    if (ts):
        print(-1)
            
    
    
        
                
        
        
        
