import math
n,t=map(int,input().split())
ans=0
mn=1000000
ch=0
for i in range(n):
    s,d=map(int,input().split())
    if not ch:
        if s-t==0:
            mn=s
            ans=i+1
            ch=1
        elif s-t >0 and s< mn:
            mn=s
            ans=i+1
            
        else:
            if s-t <0:
                re=t-s
                temp=math.ceil(re/d)
                tot=(temp*d)+s
                if tot < mn:
                    
                    mn=tot
                    ans=i+1
    print(ans)