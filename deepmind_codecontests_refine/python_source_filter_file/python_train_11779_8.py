s=input()
x,y,z=[int(x) for x in s.split(' ')]
v=input()
a,b,c=[int(x) for x in v.split(' ')]
if a>=x:
    a-=x
    if b+a>=y:
        r=b+a+c-y
        if r>=c:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')
else:
    print('NO')