R,x1,y1,x2,y2=map(int,input().split())
s=((x1-x2)**2+(y1-y2)**2)**(0.5)
sin=0
cos=1
def dist(x1,x2,y1,y2):
    return ((x1-x2)**2+(y1-y2)**2)**(0.5)
if (s>R):
    print(x1,y1,R)
else:
    r=(s+R)/2
    if s!=0:
        sin=((y2-y1)/s)
        cos=((x2-x1)/s)

    xpos,ypos=x2+r*cos,y2+r*sin
    xneg,yneg=x2-r*cos,y2-r*sin
    dis1=dist(xpos,x1,ypos,y1)
    dis2=dist(xneg,x1,yneg,y1)
    if dis1<dis2:
        print(xpos,ypos,r)
    else:
        print(xneg,yneg,r)
