from collections import Counter
import math
for ad in range(int(input())):
    n=int(input())
    x=[];z=[]
    for i in range(n):
        a,b,c,d=(list(map(int,input().split())))
        if a-c==0:
            if d>b:
                x.append(12345)
            else:
                x.append(-12345)
        elif b-d==0:
            if c > a:
                x.append(123456)
            else:
                x.append(-123456)
        else:
            k=((b-d)/(a-c))
            if k>0:
                if b-d<0 and a-c<0:
                    x.append(-k)
                else:
                    x.append(k)
            else:
                if a-c<0:
                    z.append(k)
                else:
                    z.append(-k)
    c=Counter(x)
    d=Counter(z)
    ans=0
    #print(c.keys(),c)
    y=sorted(c.keys())
    zz=sorted(d.keys())
    for i in y:
        if i<0:
            ans+=c[i]*c[-i]
        else:
            break
    for i in zz:
        if i<0:
            ans+=c[i]*c[-i]

        else:
            break
    print(ans)