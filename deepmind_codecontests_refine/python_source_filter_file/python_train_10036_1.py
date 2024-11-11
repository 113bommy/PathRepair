def gcd(a,b):
    if a<b:
        t=a
        a=b
        b=t
    if b is 0:
        return a
    return gcd(b,a%b)


x,y,a,b=input().split()
x=int(x)
y=int(y)
a=int(a)
b=int(b)


lcm=x*y/gcd(x,y)

print (b//lcm-(a-1)//lcm)
