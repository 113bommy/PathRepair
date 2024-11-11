t=int(input())
for z in range(t):
    n,x,m=list(map(int,input().split()))
    a=x-1
    b=x
    c=1
    for i in range(m):
        y,z=list(map(int,input().split()))
        if y<=a and z>=b:
            a=y
            b=z
        elif z>=b and y<=b:
            z=b
        elif y<=a and z>=a:
            a=y
    c=max(c,b-a+1)
    print(c)
    
    
    
    
        
    
    


    
    
    
        
        
            
        
        
            
    
        
        
        
        
