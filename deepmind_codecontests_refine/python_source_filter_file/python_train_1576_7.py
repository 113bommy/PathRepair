from math import cos,pi
n,r=map(int,input().split())
x=round(1-cos(2*pi/n),7)
def sol(x,r):
    y=(2*x)**2
    z=2*((x+r)**2)
    return (y/z)
low=0
high=10**9
eps=0.0000001
while high-low>eps:
    mid=(high+low)/2
    
    if sol(mid,r)>x:
        high=mid
    else:
        low=mid
print(round(high,6))
