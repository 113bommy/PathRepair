x0,y0,ax,ay,bx,by=map(int,input().split())
xs,ys,ts=map(int,input().split())
points=[[x0,y0]]
x=0;y=0
while len(points)<5 and x<10**16 and y<10**16:
    x=ax*points[-1][0]+bx
    y=ay*points[-1][1]+by
    points.append([x,y])
distance=[]
for i in range(len(points)):
    for ii  in range(i,len(points)):
        dist = (abs(xs - points[i][0]) + abs(ys - points[i][1]))

        dist+=abs(points[ii][0]-points[i][0])

        dist+=abs(points[ii][1]-points[i][1])

        if dist<=ts:
            distance.append([ii-i+1,dist])

for i in range(len(points)-1,-1,-1):

    for ii  in range(i,-1,-1):
        dist = abs(xs - points[i][0]) + abs(ys - points[i][1])

        dist+=abs(points[ii][0]-points[i][0])
        dist+=abs(points[ii][1]-points[i][1])
        if dist<=ts:
            distance.append([i-ii+1, dist])

distance.sort()
if len(distance)==0:print(0)
else:print(distance[-1][0])