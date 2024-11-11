def gcd(x,y):
    if x%y==0:
        return y
    while x%y>0:
        x,y=y,x%y
    return y
a,b,c,d=map(int,input().split())
x,y=abs(a-c),abs(b-d)
g=gcd(x,y)
print(g*(x//g+y//d-1))