import sys
x1,y1,x2,y2=[abs(int(i)) for i in input().split(" ")]
if x1==x2:
    print(x1+abs(y2-y1),y1,x2+abs(y2-y1),y2)
elif y1==y2:
    print(x1,y1+abs(x2-x1),x2,y2+abs(x2-x1))
elif abs(y2-y1)==abs(x2-x1):
    print(x1,y2,x2,y1)
else:
    print(-1)

