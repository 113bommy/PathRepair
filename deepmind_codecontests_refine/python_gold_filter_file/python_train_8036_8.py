from math import gcd
t = int(input())
for i in range(t):
    r,b,k = map(int,input().split())
    if r > b:
        r,b = b,r
    g = gcd(r,b)
    r /= g
    b /= g

    if (b-2)//r >= k-1:
        print("REBEL")
    else:
        print("OBEY")
