data=[0,2,5,7,10,12,16,18,21,23,26,28]
from math import gcd
def lcm(x,y):
    return x*y//gcd(x,y)

for _ in range(int(input())):
    n=int(input())
    a=n//12
    b=n%12
    k=12
    q=5
    cnt=0
    while (True):
        k=lcm(k,q)
        if k>n: break
        cnt+=n//k
        q+=1
    print((33*a+data[b]+cnt)%(1000000007))