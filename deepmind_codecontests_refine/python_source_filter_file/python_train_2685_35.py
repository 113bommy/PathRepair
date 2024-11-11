#ABC150_D

from fractions import gcd
N,M=map(int,input().split())
A=list(map(int,input().split()))
lcm=a[0]//2

for x in A:
    x//=2
    g=gcd(lcm,x)
    
    if (lcm//g)%2!=(x//g)%2:
        print(0)
        exit()
    
    lcm=lcm*x//g
print((M//lcm+1)//2)