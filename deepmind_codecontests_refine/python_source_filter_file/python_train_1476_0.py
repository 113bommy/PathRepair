from sys import stdin, stdout
def rsingle_int():
    return int(stdin.readline().rstrip())
 
def rmult_int():
    return [ int(x) for x in stdin.readline().rstrip().split() ]
 
def r_str():
    return stdin.readline().rstrip()
    
def rsingle_char():
    return stdin.read(1)
 
def main():
    n = rsingle_int()
    num_p = 4 * n + 1
    points = []
    for i in range(num_p):
        points.append(rmult_int())
    
    point_x = {}
    for point in points:
        if point[0] not in point_x:
            point_x[point[0]] = 0
        point_x[point[0]] += 1
    
    point_y = {}
    for point in points:
        if point[1] not in point_y:
            point_y[point[1]] = 0
        point_y[point[1]] += 1
    
    x_min = 51
    x_max = -1
    for x_key in point_x.keys():
        if x_key > x_max and point_x[x_key] > 1:
            x_max = x_key
        if x_key < x_min and point_x[x_key] > 1:
            x_min = x_key
    
    
    y_min = 51
    y_max = -1
    for y_key in point_y.keys():
        if y_key > y_max and point_y[y_key] > 1:
            y_max = y_key
        if y_key < y_min and point_y[y_key] > 1:
            y_min = y_key
    
    print((x_max, y_max), (x_min, y_min))
    found = False
    for point in points:
        if point[0] == x_max or point[0] == x_min:
            if not (point[1] <= y_max and point[1] >= y_min):
                found = True
        elif point[1] == y_max or point[1] == y_min:
            if not (point[0] <= x_max and point[0] >= x_min):
                found = True
        else:
            found = True
        if found:
            break
    if found:
        print("{} {}".format(point[0], point[1]))
    else:
        print("Error")
 
main()