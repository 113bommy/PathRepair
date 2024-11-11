t=int(input())
for i in range(t):
    n=int(input())
    h=input()
    a=[int(j) for j in h.split()]
    x=min(a)
    S=0
    for k in range(n):
        S+=a[k]-x
    if S%2==0:
        print(0)
    else:
        print(1)
        

        
    
    
        
        
            
    