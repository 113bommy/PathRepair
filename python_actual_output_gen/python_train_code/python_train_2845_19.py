n=int(input())
a=int(input())
b=int(input())
c=int(input())
if n==1:
    print('0')
l=list([a,b,c])
l.sort()
if n==2:
    print(min(a,b))

if n>3:
    x=min(a,b)
    y=min(x,c)
    print(x+(n-3)*y)
if n==3:
    x=min(a,b)
    y=min(x,c)
    print(x+y)


