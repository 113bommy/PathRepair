import math
n,R,r=map(int,input().split())
if n==1 and R>=r:
    print("YES")
elif (R-r)*math.sin(math.pi/n)+1e7>=r:
    print("YES")
else:
    print("NO")
    
