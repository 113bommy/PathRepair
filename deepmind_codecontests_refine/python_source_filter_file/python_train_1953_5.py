import math
x,y=list(map(int,input().split(' ')))
if x==1 and y==1:
    print("=")
if x==1:
    print("<")
if y==1:
    print(">")
if x<=4 and y<=4:
    l,r=x**y,y**x
    if l>r:
        print(">")
    elif l<r:
        print("<")
    else:
        print("=")
elif x<=4 and y>4:
    print(">")
elif y<=4 and x>4:
    print("<")
else:
    if x>y:
        print("<")
    elif x<y:
        print(">")
    else:
        print("=")
