t=input()
t=int(t)
for i in range(0,t):
    r,l=map(int,input().split())
    if(r==l):
        ans=0
   
    else:
        if(l%2==0):
            m=l/2
            m=int(m)
            m=m+1
            if(m in range(r,l+1)):
                ans=l%m
            else:
                ans=l%r
        else:
            m=int(l/2)
            if(m in range(r,l+1)):
                ans=m
            else:
                ans=l%r
    print(ans)                            
                
    