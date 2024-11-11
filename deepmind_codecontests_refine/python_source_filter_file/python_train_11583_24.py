import math
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    s=input().strip()
    c=0
    j=0
    dis=[]
    while j<n:
        if s[j]=='1':
            dis.append(c)
            c=0
        else:
            c=c+1
        j=j+1
    ans=0
    if dis==[]:
        ans=math.ceil(c/(k+1))
    else:
        if s[-1]!='1':
            dis.append(c)
        if s[0]=='0':
            if dis[0]-k>=1:
                ans=ans+math.ceil((dis[0]-k)/(k+1))
                del dis[0]
            else:
                del dis[0]
        if len(dis)>=1:
            if s[-1]=='0':
                if dis[-1]-k>=1:
                    ans=ans+math.ceil((dis[0]-k)/(k+1))
                    del dis[-1]
                else:
                    del dis[-1]
        for v in dis:
            if v-2*k>=1:
                ans=ans+math.ceil((v-(2*k))/(k+1))
    print(ans)
        
                    
        
        
        
        
