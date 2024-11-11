t=int(input())
for x in range(t):
    n,r=map(int,input().split())
    if n>r:
        m=r*(r+1)//2
        print(m)
    else:
        m=n*(n-1)//2+1
        print(m)
        
            
            
    
