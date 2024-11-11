a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
if e<f:
    t=min(b,c,d)
    print(f*t+min(d,d-t)*e)
else:
    t=min(b,c,d)
    print(e*t+min(b,c,d-t)*f)