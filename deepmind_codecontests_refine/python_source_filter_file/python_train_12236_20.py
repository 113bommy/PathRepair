n,a,b=[int(x) for x in input().split()]
if b==0:
    print(a)
elif b>0:
    c=a+b%n
    if c>6:
        print(c-6)
    else:
        print(c)
else:
    c=a-abs(b)%n
    if c<=0:
        print(6+c)
    else:
        print(c)
