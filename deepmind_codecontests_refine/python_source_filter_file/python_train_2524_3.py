for i in range(int(input())):
    n,x=map(int,input().split())
    a=[int(i) for i in input().split()]
    s=sum(a)
    ans=0
    i=0
    j=n-1
    m=1000000
    g=1000000
    if s%x!=0:
        ans=n
        print(ans)
    else:
        for i in range(n):
            if (s-a[i])%x!=0:
                m=i+1
                #print(m)
                break
            else:
                s=s-a[i]
        s=sum(a)
        for j in range(n-1,-1,-1):
            
            if (s-a[j])%x!=0:
                g=abs(j-n)+1
                break
            else:
                s=s-a[j]
    
        if m<n or g<n:
            print(n-min(m,g))
        else:
            print(-1)  