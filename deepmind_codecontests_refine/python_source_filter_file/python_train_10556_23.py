x,y = map(int,input().split())
if x>0 and y>0:
    print(0,x+y,x+y,0)
elif x<0 and y>0:
    print(x-y,0,0,abs(x)+abs(y))
elif x>0 and y<0:
    print(0,y-x,abs(x)+abs(y),0)
else:
    print(x+y,0,0,abs(x+y))
