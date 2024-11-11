n,m=map(int, input().split())
if(m%n!=0):
    print(-11)
else:
    ans=0
    m=m/n
    while(m%2==0):
        m=m/2
        ans+=1
    while(m%3==0):
        m=m/3
        ans+=1  
    m=int(m)    
    
    if(m!=1):
        print(-1)
    else:
        print(ans)