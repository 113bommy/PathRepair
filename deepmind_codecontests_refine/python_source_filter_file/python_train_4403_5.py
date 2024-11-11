t=int(input())
while(t>0):
    n=int(input())
    a=list(map(int,input().split()))
    i=a.index(1)
    a=a[::-1]
    j=a.index(1)
    j=(n-1)-j
    a=a[::-1]
    ans=i
    #print(i,j,a)
    for k in range(i,j):
        if(a[k]==0):
            ans+=1
    j=(n-1)-j
    a=a[::-1]
    ans2=j
    i=(n-1)-i
    #print(i,j,a)
    for k in range(j,i):
        if(a[k]==0):
            ans2+=1
    print(min(ans,ans2))
    
    
    t-=1
