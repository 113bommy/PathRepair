t=int(input())
s=[]
for kngg in range(0,t):
    x=input()
    xx=x.split( )
    xx[0]=int(xx[0])
    xx[1]=int(xx[1])
    xx.sort()
    a=xx[0]
    b=xx[1]
    while a!=0:
        b-=a
        if a>b:
            c=b
            b=a
            a=c
    if b==1:
        s.append('finit')
    else:
        s.append('infinit')
for i in s:
    print(i)
