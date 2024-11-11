import math
n,m=input().split(" ")
n=int(n)
m=int(m)
if m>=math.ceil(n/2) :
    print(int(n/2-(m-n/2)))
elif m==0:
    print(1)
elif n==m:
    print(0)
else:
    print(m)
    
