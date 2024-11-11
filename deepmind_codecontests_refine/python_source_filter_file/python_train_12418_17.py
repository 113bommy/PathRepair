from math import ceil
for _ in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    r=ceil(n/2)
    t=k
    p=n*k
    ans=0
    i=0
    if(n>2):
        while(i<k):
            p=p-(n-(r-1))
            ans=ans+l[p]
            i=i+1
    else:
        for i in range(0,n*k,2):
            ans=ans+l[i]
    print(ans)
            