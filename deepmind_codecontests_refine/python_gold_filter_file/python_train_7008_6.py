import math
t = int(input())
m = 1000000007
while(t):
    n = int(input()) 
    i ,y, res = 2, 2, (2*n)%m
    while(y<=n):
        y = y*i//math.gcd(y, i)
        res = (res + n//y)%m
        i+=1
    print(res)
    t-=1