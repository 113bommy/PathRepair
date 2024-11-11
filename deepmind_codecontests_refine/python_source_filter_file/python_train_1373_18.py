
def fun(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6):
    if y3 <= y1 and y4 >= y2 and x3 <= x1 and x5 <= x4 and y5 <= y1 and y6 >= y2 and x6 >= x2 and x4 < x2:
        return True
    return False

def fun2(x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4):
    if x3<=x1 and x4>=x2 and y4>=y2 and y3<=y1:
        return True 
    return False

def fun3(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6):
    if x3>=x1 and x4>=x2 and x5<=x1 and x6>=x2 and y4>=y2 and y6>=y3 and y5<=y1 and y3 > y1:
        return True
    return False

x1 , y1 , x2 , y2 = map(int,input().split())
x3 , y3 , x4 , y4 = map(int,input().split())
x5 , y5 , x6 , y6 = map(int,input().split())

ok = False
if fun2(x1,y1,x2,y2,x3,y3,x4,y4):
    ok = True
    # print(ok , 1)
if fun2(x1,y1,x2,y2,x5,y5,x6,y6):
    ok = True
    # print(ok , 2)
if fun(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6):
    ok = True
    # print(ok , 3)
if fun(x1,y1,x2,y2,x5,y5,x6,y6,x3,y3,x4,y4):
    ok = True
    # print(ok , 4)

if fun3(x1,y1,x2,y2,x5,y5,x6,y6,x3,y3,x4,y4):
    ok = True
    # print(ok , 5)
if fun3(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6):
    ok = True
    # print(ok , 6)
if(ok):
    print("NO")
else:
    print("YES")