##n,m,k=list(map(int,input().split()))
##p=list(map(int,input().split()))
##p.sort()
##import math
##ok=k
##ip=0
##s=1
##cnt=0
##a=False
##for i in p:
##    
##    if ip<i<=k:
##        
##        cnt+=1
##        
##        a=True
##    elif ip<i<=k+cnt:
##        
##        s+=1
##        k+=cnt+1
##        a=True
##        
##        
##    else:
##        if ip==0 and k+cnt==ok:
##            s=0
##        l=math.ceil((i-k)/ok)
##        ip=k+ok*(l-1)
##        
##        k+=ok*l
##        
##        s+=1
##        
##        cnt=0
##       
##   
##    
##    
##        
##        
##print(s)
##        
##        
##    
##    
##
import math
n,m,k=list(map(int,input().split()))
p=list(map(int,input().split()))
p.sort()
ok=k
ip=0
s=0
if ok==1:
    print(len(p))
else:
    while ip<n and p:
        m=False
        cnt=0
        o=0
        while o<len(p):
            
            if ip<p[o] and p[o]<=k:
                
                m=True
                cnt+=1
                p.pop(o)
                o-=1
            else:
                
                break
            o+=1
        if m:
            s+=1
            
            k+=cnt
            
            
        else:
            
            l=math.ceil((p[o]-k)/ok)
            
            ip=k+ok*(l-1)
            k+=ok*l
           
            
        
        
    print(s)
