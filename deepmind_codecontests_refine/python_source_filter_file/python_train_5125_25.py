t=int(input())
while(t>0):
    n,d=[int(x) for x in input().split()]
    l=[int(x) for x in input().split()]
    if(n==1):
        print(l[0])
    else:
        ans=l[0]
        for i in range(1,n):
            l[i]=i*l[i]
        for i in range(1,n):
            if((d-l[i])>=0):
                d-=l[i]
                ans+=l[i]
            else:
                ans+=(d//i)
                break
        print(ans)
    t-=1
