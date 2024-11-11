x,y = map(int,input().split())
if 0<+x<=1 and y==0:
    print(0)
elif x>=0 and y>0:
    if y<=x:
        print(4*x - 3)
    else:
        print(4*y - 2)
elif x<0 and y>=0:
    if y >= abs(x):
        print(4*y - 2)
    else:
        print(4*abs(x)-1)
elif x<=0 and y<0:
    if abs(y)<=abs(x):
        print(4*abs(x)-1)
    else:
        print(4*abs(y))
else:
    if abs(y)>=x:
        print(4*y)
    else:
        print(4*x - 3)