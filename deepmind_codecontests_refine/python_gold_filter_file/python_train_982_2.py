n,k,d=map(int,input().split())
if(n>pow(k,d)):
    print(-1)
else:
    temp=[]
    ans=[1]*d
    temp.append(ans)
    m=n
    m-=1
    count=1
    r=1
    while(m):
        ans=[0 for i in range(d)]
        count=r
        
        for i in range(d):
            ans[len(ans)-1-i]=count%k
            count=count//k
    
        for i in range(len(ans)):
            ans[i]+=1
        temp.append(ans)
        r+=1
        m-=1
    for i in range(d):
        for j in range(len(temp)):
            print(temp[j][i],end=" ")
        print(' ')
        
