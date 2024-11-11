from math import *
n,m=map(int,input().split())
q1=m//2
q2=m//2 + m%2
maxx=min(q1,n-q2+1)
if m%2==0:
    maxx-=1
print(max(maxx,0))