n=int(input())
m=int(input())
if n>=m//2:
    print(m)
else:
    r=1
    a=2
    while n>0:
        if n%2:
            r=r*a
            n=n-1
        else:
            a=a*a
            n=n//2
    print(m%r)