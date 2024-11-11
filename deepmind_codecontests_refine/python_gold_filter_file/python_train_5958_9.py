import math
for t in range(int(input())):
    n,g,b=map(int,input().split())
    m=math.ceil(n/2)
    if(g>=n):
        print(n)
    else:
        groups=math.ceil(m/g)
        ans=m+(groups-1)*b
        print(max(ans,n))
    
