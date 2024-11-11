x, y, n=map(int,input().split())
a=(x//n)+(y//n)
b=(x+y)//n
if a==b:
    print(a,0)
else:
    m1=x%n
    m2=y%n
    print(b,end=" ")
    if m1<m2:
        print(m1)
    else:
        print(m2)
    