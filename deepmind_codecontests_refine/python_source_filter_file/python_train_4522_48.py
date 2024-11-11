def get_position(position):
    y, x = position
    y = ord(y)-ord('a')
    x = 8 - int(x)
    return x,y
    

source = input()
destination = input()
source_x, source_y = get_position(source)
destination_x, destination_y = get_position(destination)
#print(source_x, source_y)
#print(destination_x, destination_y)
if source_x == destination_x and source_y == destination_y:
    print(0)
elif source_x == destination_x:
    d = abs(source_y-destination_y)
    print(d)
    if source_y<destination_y:
        for i in range(d):
            print("R")
    else:
        for i in range(d):
            print("L")        
elif source_y == destination_y:
    d = abs(source_x-destination_x)
    print(d)
    if source_x<destination_x:
        for i in range(d):
            print("D")
    else:
        for i in range(d):
            print("U")

elif (source_x - destination_x) == (source_y - destination_y):
    d = abs(source_x-destination_x)
    print(d)
    if source_x<destination_x:
        for i in range(d):
            print("RD")
    elif source_x>destination_x:
        for i in range(d):
            print("RU")
    elif source_y<destination_y:
        for i in range(d):
            print("LD")
    elif source_y>destination_y:
        for i in range(d):
            print("LU")
else:
    if source_x<destination_x and source_y<destination_y:
        dx = abs(source_x-destination_x)
        dy = abs(source_y-destination_y)
        diag = min(dx, dy)
        line = max(dx, dy) - diag
        print(diag + line)
        for i in range(diag):
            print("RD")
            source_x += 1
            source_y += 1
        if source_y == destination_y:
            for i in range(line):
                print("D")        
        else:
            for i in range(line):
                print("R")                    
    elif source_x<destination_x and source_y>destination_y:
        dx = abs(source_x-destination_x)
        dy = abs(source_y-destination_y)        
        diag = min(dx, dy)
        line = max(dx, dy) - diag
        print(diag + line)
        for i in range(diag):
            print("LD")
            source_x += 1
            source_y -= 1
        if source_y == destination_y:
            for i in range(line):
                print("D")        
        else:
            for i in range(line):
                print("L")            
    elif source_x>destination_x and source_y<destination_y:
        dx = abs(source_x-destination_x)
        dy = abs(source_y-destination_y)        
        diag = min(dx, dy)
        line = max(dx, dy) - diag
        print(diag + line)
        for i in range(diag):
            print("RU")
            source_x += 1
            source_y -= 1
        if source_x == destination_x:
            for i in range(line):
                print("R")
        else:
            for i in range(line):
                print("U")        
    elif source_x>destination_x and source_y>destination_y:
        dx = abs(source_x-destination_x)
        dy = abs(source_y-destination_y)      
        diag = min(dx, dy)
        line = max(dx, dy) - diag
        print(diag + line)
        for i in range(diag):
            print("LU")
            source_x -= 1
            source_y -= 1
        if source_x == destination_x:
            for i in range(line):
                print("L")
        else:
            for i in range(line):
                print("U")            
"""
a8
h1


Input
h1
b2
7 7
6 1

Output
7
LU
U
U
U
U
U
U
Answer
6
LU
L
L
L
L
L
"""
