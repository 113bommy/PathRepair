n=int(input())
d=1
s=0
for i in range(0,n):
    a,b=input().split(' ')
    a=int(a)
    b=int(b)
    s=d
    if i==0 or d<=a:
        d=a
    else:
        import math
        e=math.ceil((d-a)/b)
        d=a+e*b
    if s>=d and i!=0:
        d+=b
print(d)
