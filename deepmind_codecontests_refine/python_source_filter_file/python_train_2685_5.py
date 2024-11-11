import sys

def gcd(x,y):
    while y:
        x,y = y , x % y 
    return x

n,m=map(int,input().split())
a=map(int,input().split())

lcm = 1
for i in a:
    lcm = lcm * i // gcd(lcm,i)
for i in a:
    if (lcm/i)%2 == 0:
        print(0)
        sys.exit()
print((m+lcm//2)//lcm)