ax,ay,bx,by,cx,cy = map(int,input().split())
if (ax-bx)*(ax-bx) + (ay-by)*(ay-by) == (bx-cx)*(bx-cx) + (by-cy)*(by-cy):
    if (ax==bx and bx==cx):
        print("NO")
    elif ax==bx or bx==cx:
        print("YES")
    elif (by-ay)/(bx-ax)*(cy-by)/(cx-bx)>=0 and abs((by-ay)/(bx-ax)-(cy-by)/(cx-bx))<10**13:
        print("NO")
    else:
        print("YES")
else:
    print("NO")