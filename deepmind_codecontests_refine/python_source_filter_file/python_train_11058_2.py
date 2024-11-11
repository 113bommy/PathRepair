t=int(input())
while(t):
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    ma1,ma2=-float('inf'),-float('inf')
    c,d=[],[]
    print(a)
    if(n%2):
        for i in range(2*n):
            if(i%2==0):
                c.append(a[i])
            else:
                d.append(a[i])
        c.sort()
        d.sort()
        x=c[n//2]
        y=d[n//2]
        print(c,d)
        print(abs(x-y))
    else:
        n=2*n
        x=a[n//2]
        y=a[(n//2)-1]
        print(abs(x-y))
        
