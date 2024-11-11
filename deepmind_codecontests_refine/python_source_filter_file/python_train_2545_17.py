points = list(map(int,input().split()))
newpoints = None
if (points[2]-points[0])==0:

    distance = abs(points[3]-points[1])
    newpoints= points[0]+distance, points[1],points[2]+distance, points[3]
else:
    if (points[3]-points[1])==0:
        distance = abs(points[2]-points[0])
        newpoints= points[0], points[1]+distance,points[2], points[4]+distance  
    else:
        if (points[3]-points[1])== points[2]-points[0]:
            newpoints = points[0],points[3],points[2],points[1]
        else:
            newpoints= -1
if(type(newpoints) is int):
    print(newpoints)
else:
    print(' '.join(str(x) for x in newpoints))
