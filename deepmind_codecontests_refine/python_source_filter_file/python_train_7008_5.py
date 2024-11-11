import math

n = int(input())
b = []
for i in range(n):
    b.append(int(input()))

def lcm(a, b):
    return abs(a*b) // math.gcd(a, b)

def sana(x):
    i = 2
    d = 1
    b = 0
    y = x
    if x==1:
        return 2
    elif x==2:
        return 5
    else:
        while(y!=0):
            if d%i != 0:
                d = lcm(d,i)
                a = int(x/d)
                b = b + (y-a)*i
                y = a
            i+=1
    if(len(str(b)) >= 10):
        b = b%(10**9+7)
    return b

for i in b:
    print(sana(i))





