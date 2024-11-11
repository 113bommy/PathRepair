t=int(input())
for u in range(t):
    b,p,f=input().split()
    b,p,f=int(b),int(p),int(f)
    h,c=input().split()
    h,c=int(h),int(c)
    ham=0
    chi=0
    
    if(h>c):
        while(b>1 and p>0):
            ham+=1
            b-=2
            p-=1
        
        while(b>1 and f>0):
            chi+=1
            b-=2
            f-=1
    else:
        while(b>1 and f>0):
            chi+=1
            b-=2
            f-=1
            
        while(b>1 and p>0):
            ham+=1
            b-=2
            p-=1
    ans=ham*h+chi*c
    print(ans)
            
                
    
        
        
        
        
