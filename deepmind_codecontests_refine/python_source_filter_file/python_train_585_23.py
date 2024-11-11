import math
k,d,t=map(int,input().split())
if k>=t:
    print(t)
elif k>=d and k%d==0:
    print(t)
else:
    if k!=0:
        p=math.ceil(k/d)
        r=(p*d)-k
        f=(k/t)+((r)/(2*t))
        m=math.ceil(1/f)
        print(m)
        n=m-1
        req=1-(n*f)
        if n*f+(k/t)>1:
            s=req*t
           # print(s)
            ans=n*(p*d)+s
            print(ans)
        elif n*f+(k/t)==1:
            ans=n*(p*d)+k
            print(ans)
        else:
            re=1-((n*f)+(k/t))
            s=re*(2*t)
          #  print(s)
            ans=n*(p*d)+k+s
            print(ans)
    
        