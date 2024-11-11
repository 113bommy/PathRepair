from math import sqrt
_Ans=-1
C=[]
n,s=list(map(int,input().split()))
for i in range(n):
    x,y,s1=list(map(int,input().split()))
    C=C+[[sqrt(x*x+y*y),s1]]
if s>=1000000:
    _Ans=0
else:
    C.sort()
    i=0
    while s<1000000 and i<n:
        _Ans=C[i][0]
        s+=C[i][1]
        i+=1
if s>=1000000:  print(_Ans)
else:   print(-1)