# M. Quadcopter Competition
x1,y1 = map(int,input().split())
x2,y2 = map(int,input().split())
if x1==x2:
    p=2*abs(y1-y2)+6
elif y2==y1:
    p=2*abs(x1-x2)+6
else:
    p=abs(x1-x2)*2+abs(y1-y2)*2+4
print(p)