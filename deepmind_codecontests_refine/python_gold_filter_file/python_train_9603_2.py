import math                   
t=int(input())
for i in range(t):
    a,b,c,d=input().split()
    a=int(a)
    b=int(b)
    c=int(c)
    d=int(d)
    
    if d>=c and a>b:
        print("-1")
    elif b>=a:
        
        print(b)
    elif c==d:
        l=math.ceil((a-b)/c)
        print(b+l*c)
       
    else:
        k=(c-d)
        k1=a-b
        k2=math.ceil(k1/k)
        #print(k2)
        print(b+k2*c)
    
    
        
        
            
    
             
    
                
           
                
            
                
            
        
          
   
            
        
        
        
    