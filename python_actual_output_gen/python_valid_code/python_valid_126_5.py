n,x=map(int,input().split())
formula=0
i=0
if(n==1):
    print(0)
else:
    formula=10^9
    while(abs(n-(i+formula))!=x):
        i=i+1
        formula=(i*(i+1))//2
    print(abs(n-i))
    

    
    
    
    
    
        
    

    



        
        

