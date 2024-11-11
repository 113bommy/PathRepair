from math import *
n=int(input())
m=int(sqrt(n))
if m*m==n:
    print(4*m)
else:
    i=m*m
    j=(m+1)*(m+1)
    if(abs(j-n)<abs(j-n)):
        a=((2*m)+1)*2
    else:
        a=4*(m+1)
    print(a)
