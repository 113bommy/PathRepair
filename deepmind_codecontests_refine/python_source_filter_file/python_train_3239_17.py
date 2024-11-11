import math
n,m=map(int,input().split())
if m==0:
    print(n)
    exit(0)
a=max(0,n-2*m)
b=math.ceil((1+math.sqrt(1+8*m))/2)
print(a,int(n-b))