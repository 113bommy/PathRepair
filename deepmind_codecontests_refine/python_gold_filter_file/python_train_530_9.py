def calculate(points,surface):
    if (sum(points) % 2 !=0 and surface %2 !=0  ):
        return surface//2+1
    return surface//2
result = []
n = int(input())
_inpu,x,y = [],set(),set()
for _ in range(n): 
    _inpu.append([*map(int,input().split()),[int(i) for i in input().split()],[int(i) for i in input().split()]])

for el in _inpu:
    surface = el[0]*el[1]
    black = surface//2
    if surface %2 !=0:
        white = black+1
    else:
        white = black   
    points,black_points = el[2:] 
    # we're calculating the surface of black square to added to white variable      
    surface = (points[2] - points[0] + 1) * (points[3] - points[1] + 1)
    add =  calculate(points[0:2],surface)
    white+=add
    black-=add
    # we're checking the intersect points of black and white squares
    black_x = [black_points[0],black_points[2]]
    black_y = [black_points[1],black_points[3]]
    white_x = [points[0],points[2]]
    white_y = [points[1],points[3]]
    if black_x[1]>=white_x[0] and black_x[0]<= white_x[1] :
        if black_x[1]>white_x[1]:
            x.add(white_x[1])
        else:
            x.add(black_x[1])
        if black_x[0]>=white_x[0]:
            x.add(black_x[0])
        else:
            x.add(white_x[0])
    if black_y[1]>=white_y[0] and black_y[0] <= white_y[1]:
            if black_y[1]>=white_y[1]:
                y.add(white_y[1])
            else:
                y.add(black_y[1])
            if black_y[0]>=white_y[0]:
                y.add(black_y[0])
            else:
                y.add(white_y[0])
    if x and y:
        # we're trying to return the mispainted black points by calcuting the surface 
        surface = (max(x)-min(x)+1)*(max(y)-min(y)+1)
        add = calculate([min(x),min(y)], surface)
        black+=add
        white-=add
    
    # we calculate the surface of black painting 
    surface = (black_points[2] - black_points[0] + 1) * (black_points[3] - black_points[1] + 1)
    add = surface - calculate(black_points[0:2], surface)
    black+=add
    white-=add
    result.append([white,black])
    x.clear()
    y.clear()
for i in result:
    print(*i,end='\n')