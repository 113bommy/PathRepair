from math import *
n,m=map(int,input().split())
q1=n//2
q2=n//2 + n%2
maxx=min(q1,m-q2+1)
if m%2==0:
    maxx-=1
print(max(maxx,0))