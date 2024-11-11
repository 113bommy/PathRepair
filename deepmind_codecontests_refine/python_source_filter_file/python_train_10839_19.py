e=int(input())
for i in range(0,e):
    a,b,c=input().split()
    a=int(a)
    b=int(b)
    c=int(c)
    if c%2==0:
        d=a*(c/2)-b*(c/2)
    else:
        d=a*((c//2)+1)-b*(c//2)
    d=int(d)
    print(d)
        