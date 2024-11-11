import math 
a, b, c, d = map(int, input().split())
x =0
y = 0
if(a/b < c/d):
    x = (b*c - a*d)
    y = b*c
    z = math.gcd(x, y)
    x = x//z
    y = y//z
    print(str(x)+"/"+str(y))

elif(a/b > c/d):
    x = (a*d - b*c)
    y = a*d
    z = math.gcd(x, y)
    x = x//z
    y = y//z
    print(str(x)+"/"+str(y))

else:
    print("0/1")

