t=int(input())
c=1
while c<=t:
    x,y,a,b=(input().split(' '))
    x=int(x)
    y=int(y)
    a=int(a)
    b=int(b)
    q=y-x
    w=a+b
    if q%w==0:
        d=q/w
    else:
        d==-1
    print(d)
    c+=1
