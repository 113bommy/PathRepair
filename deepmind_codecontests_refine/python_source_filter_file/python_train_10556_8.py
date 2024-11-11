
x,y = [int(x) for x in input().split()]
if x>0 and y>0:
    x1,y1,x2,y2 = 0,x+y,x+y,0
elif x<0 and y<0:
    x1,y1,x2,y2 = 0,x+y,x+y,0
elif x<0 and y>0:
    x1,y1,x2,y2 = -(abs(x)+abs(y)),0,0,abs(x)+abs(y)
elif x>0 and y<0:
    x1,y1,x2,y2 = 0,-(abs(x)+abs(y)),abs(x)+abs(y),0
print(x1,y1,x2,y2)
