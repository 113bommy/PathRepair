def area(x1, y1, x2, y2, x3, y3):
    return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2)


from math import ceil, log
t = 1
for test in range(t):
    c = list(map(int, input().split()))
    b = list(map(int, input().split()))
    Area = area(b[0], b[1], b[2], b[3], b[4], b[5]);
    Area+=area(b[0], b[1], b[6], b[7], b[4], b[5])
    # Area+=1 
    flag = False
    maxx = max(c[0], c[2], c[4])   
    minx = min(c[0], c[2], c[4])
    maxy = max(c[1], c[3], c[5]) 
    miny = min(c[1], c[3], c[5])
    a = [minx, miny, maxx, miny, maxx, maxy, minx, maxy]
    # print(a)
    for x in range(a[0], a[2]):
        tmp = area(x, a[1], b[0], b[1], b[2], b[3])
        tmp+=area(x, a[1], b[4], b[5], b[2], b[3])
        tmp+=area(x, a[1], b[6], b[7], b[4], b[5])
        tmp+=area(x, a[1], b[0], b[1], b[6], b[7])
        # print(tmp,Area)
        if tmp<=Area:
            flag = True
            break;        
    for x in range(a[0], a[2]):
        tmp = area(x, a[5], b[0], b[1], b[2], b[3])
        tmp+=area(x, a[5], b[4], b[5], b[2], b[3])
        tmp+=area(x, a[5], b[6], b[7], b[4], b[5])
        tmp+=area(x, a[5], b[0], b[1], b[6], b[7])

        if tmp<=Area:
            flag = True
            break;
    for y in range(a[1], a[5]):
        tmp = area(a[0],y , b[0], b[1], b[2], b[3])
        tmp+=area(a[0],y, b[4], b[5], b[2], b[3])
        tmp+=area(a[0],y, b[6], b[7], b[4], b[5])
        tmp+=area(a[0],y, b[0], b[1], b[6], b[7])

        if tmp<=Area:
            flag = True
            break;
    for y in range(a[1], a[5]):
        tmp = area(a[2],y , b[0], b[1], b[2], b[3])
        tmp+=area(a[2],y, b[4], b[5], b[2], b[3])
        tmp+=area(a[2],y, b[6], b[7], b[4], b[5])
        tmp+=area(a[2],y, b[0], b[1], b[6], b[7])

        if tmp<=Area:
            flag = True
            break;

    if flag:
        print("YES")
    else:
        Area = area(a[0], a[1], a[2], a[3], a[4], a[5])
        Area+=area(a[0], a[1], a[6], a[7], a[4], a[5])
        # Area+=1
        tmp = area(b[0], b[1], a[0], a[1], a[2], a[3])
        tmp+=area(b[0], b[1], a[4], a[5], a[2], a[3])
        tmp+=area(b[0], b[1], a[6], a[7], a[4], a[5])
        tmp+=area(b[0], b[1], a[0], a[1], a[6], a[7])
        # print(tmp, Area)
        if tmp<=Area:
            print("YES")
        else:
            print("NO")





    

