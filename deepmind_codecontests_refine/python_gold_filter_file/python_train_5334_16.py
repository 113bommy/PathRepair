for i in range(int(input())):
    a,b,c,d = list(map(int,input().split()))
    x,y,x1,y1,x2,y2 = list(map(int,input().split()))
    if ( (x + b-a >= x1 and x + b-a <= x2) and (y + d-c >= y1 and y + d - c <= y2)):
        if (x2-x1 == 0 and (a != 0 or b != 0)) or (y2 - y1 == 0 and (d != 0 or c != 0)):
            print('NO')
        else:
            print("YES")
    else:
        print('NO')