import math
n,m=map(int,input().split())
e,p,g,v=list(map(int, input().split())),list(map(int, input().split())),0,0
for i in range(1,n):g=math.gcd(g,e[i]-e[i-1])
for i in range(m):v=i if not g%p[i] else v
if v:print("YES",e[0],v+1)
else:print("NO")