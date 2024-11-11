x,y=map(int,input().split())
X=abs(x)
Y=abs(y)

if y>=x>=0 or 0>=y>=x:
    print(abs(y-x))
elif x>y>=0 or 0>x>y:
    print(x-y+2)
else:
    print(abs(X-Y)+1)