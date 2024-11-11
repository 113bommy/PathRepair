z=int(input())
import math

for j in range(z) :
    n=int(input())
    if n%2==0 :
        total=(n//2*n+n//2)
    else :
        total=((n//2+1)*n)
    minus=0
    temp=0
    while abs(minus)<=n :
        minus+=(2**temp)
        temp+=1
    print(total-minus*2)
