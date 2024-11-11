x1,y1,x2,y2 = map(int,input().split())
x,y = map(int,input().split())
if (x2-x1)%x == 0 and (y2-y1)%y == 0 and abs(x2-x1)//x - abs(y2-y1)//y%2 == 0:
    print("YES")
else:
    print("NO")
    