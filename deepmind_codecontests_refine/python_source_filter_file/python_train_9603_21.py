import math
for _ in range(int(input())):
    a,b,c,d=map(int,input().split())
    Ans=a-b
    if Ans<=0:print(b)
    else:
        k=a-b;Ans=b
        if d>=c:
            print(-1)
        else:
            t=math.ceil(k//(c-d));Ans+=(t*c)
            print(Ans)    
            