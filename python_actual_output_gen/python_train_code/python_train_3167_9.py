l=input().split(" ")
n=int(l[0])
a=int(l[1])
b=int(l[2])
c=int(l[3])
d=int(l[4])
x=1
y=n
m=min(x+b-c,x+a-d,a+b-c-d+x)
g=max(y+b-c,y+a-d,y+b-c-d+y)
if m<1:
    x+=1-m
if g>n:
    y+=n-g
if x>y:
    print(0)
else:
    print(n*(y-x+1))