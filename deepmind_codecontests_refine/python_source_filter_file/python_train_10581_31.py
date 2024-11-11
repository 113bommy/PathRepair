x=input()
xx=x.split( )
n=int(xx[0])
m=int(xx[1])
j=1e100000000000000000
for ikv in range(0,n):
    x=input()
    xx=x.split( )
    a=int(xx[0])
    b=int(xx[1])
    f=a/b
    if f<j:
        j=f
print(f*m)
