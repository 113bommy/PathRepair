x1,y1,x2,y2 = [int(x) for x in input().split()]
x3,y3,x4,y4 = [int(x) for x in input().split()]
x5,y5,x6,y6 = [int(x) for x in input().split()]

def CheckPointInsideSQ(x,y,x1,y1,x2,y2):
    if (x1<=x<=x2 and y1<=y<=y2):
        return True
    else:
        return False
##23
##01
Corners1=[0]*4
if CheckPointInsideSQ(x1,y1,x3,y3,x4,y4):
    Corners1[0]=1
if CheckPointInsideSQ(x2,y2,x3,y3,x4,y4):
    Corners1[3]=1
if CheckPointInsideSQ(x1,y2,x3,y3,x4,y4):
    Corners1[2]=1
if CheckPointInsideSQ(x2,y1,x3,y3,x4,y4):
    Corners1[1]=1
Corners2=[0]*4

if CheckPointInsideSQ(x1,y1,x5,y5,x6,y6):
    Corners2[0]=1
if CheckPointInsideSQ(x2,y2,x5,y5,x6,y6):
    Corners2[3]=1
if CheckPointInsideSQ(x1,y2,x5,y5,x6,y6):
    Corners2[2]=1
if CheckPointInsideSQ(x2,y1,x5,y5,x6,y6):
    Corners2[1]=1

Covered=False
if (sum(Corners1)==4 or sum(Corners2)==4):
    Covered=True
if(Corners1[0]==1 and Corners1[2]==1 and Corners2[3]==1 and Corners2[1]==1 and x4>=x5):
    Covered=True

if(Corners2[0]==1 and Corners2[2]==1 and Corners1[3]==1 and Corners1[1]==1 and x3<=x6):
    Covered=True

if(Corners1[0]==1 and Corners1[1]==1 and Corners2[2]==1 and Corners2[3]==1 and y4>=y5):
    Covered=True

if(Corners2[0]==1 and Corners2[1]==1 and Corners1[2]==1 and Corners1[3]==1 and y6>=y3):
    Covered=True
if Covered:
    print("YES")
else:
    print("NO")