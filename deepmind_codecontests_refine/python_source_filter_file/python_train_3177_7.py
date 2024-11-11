a,b,c = map(int,input().split())
x,y,z = map(int,input().split())

a-=x
b-=y
c-=z
if a>0:
    a/=2
if b>0:
    b/=2
if c>0:
    c/=2


if a+b+c>=0:
    print ('Yes')
else:print ('No')