
tests=int(input())
for _ in range(tests):
    n=int(input())
    x=2
    a=[0]*11
    y=10
    t=1
    ans=0
    while(n+x//2>x):
        z=(n+x//2)//x
        ans+=t*z
    
        t+=1
        
        x=pow(2,t)
    

    print(ans)

    

            
        


    

        


    
