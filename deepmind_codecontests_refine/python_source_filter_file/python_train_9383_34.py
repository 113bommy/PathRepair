n,k,m=map(int,input().split())
x=list(map(int,input().split()))
a=0
xx=set(x)
import math
nn=math.ceil(n/2)
if len(xx)<nn:
    if m>n:
        #halat khas:
        x=sorted(x,reverse=True)
        m=m-(n-1)
        if m<0:
            m=abs(m)+1
            a=0
            for i in range(0,m):
                a+=x[i]
            print(a/m)
        else:
            print(x[0]+min(m,k))
        #
    else:
        x=sorted(x)
        c=n
        maxx=x[n-1]
        t=x.count(maxx)
        if t>=nn:
            #more than half is maxx: Del
            for i in range(0,n):
                if x[i]==maxx:
                    a+=x[i]
                else:
                    if m>0:
                        c-=1
                        m-=1
            a+=min(k*c,m)
            print(a/c)
        else:
            #less than half is maxx: Icr
            a=sum(x)+min(k*n,m)
            print(a/n)                
else:
    x=sorted(x,reverse=True)
    m=m-(n-1)
    if m<0:
        m=abs(m)+1
        a=0
        for i in range(0,m):
            a+=x[i]
        print(a/m)
    else:
        print(x[0]+min(m,k))