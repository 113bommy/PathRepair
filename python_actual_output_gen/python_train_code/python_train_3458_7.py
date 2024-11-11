#Time:2014/08/29

x,y,a,b = input().split()
a=int(a)
b=int(b)
x=int(x)
y=int(y)
if x<y :
    r=x
    x=y
    y=r
g=x*y
r=x%y
while r!=0 :
    x=y
    y=r
    r=x%y
g=int(g/y)
if g>=a :
    num=int((b-g)/g)+1
    if g>b :
        num=0
else :
    if a%g==0 :
        k=a
    else :
        k=int(a/g+1)*g
    num=int((b-k)/g)+1
    if g>b :
        num=0
print(num)
