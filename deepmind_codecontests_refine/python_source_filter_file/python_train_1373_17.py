x1,y1,x2,y2=map(int,input().split())
x3,y3,x4,y4=map(int,input().split())
x5,y5,x6,y6=map(int,input().split())
#l,l1,b,b1,o=0,0,0,0,0
if y4>=y2 and y1>=y3 and x1>=x3 and x2<=x4:
    print("NO")
   # print("1")
elif y6>=y2 and y1>=y5 and x1>=x5 and x2<=x6: 
    print("NO")
   # print("2")
elif x2>x3 and x4>x2 and y4>=y2 and y1>=y3:
    if x5<=x1 and x6>=x3 and y1>=y4 and y2<=y6:
        print("NO")
       # print("3")
    else:
        print("YES")
       # print("5")
elif x1>=x3 and x4<x2 and y4>=y2 and y1>=y3:
    if x5<=x4 and x6>=x2 and y1>=y5 and y2<=y6:
        print("NO")
       # print("6")
    else:
        print("YES")
#print("7")
elif y4>=y2 and y3<y2 and x3<=x1 and x4>=x2:
    if y6>=y3 and y5<=y1 and x5<=x1 and x2<=x6:
        print("NO")
       # print("8")
    else:
        print("YES")
       # print("9")
elif y3<=y1 and y4>y1 and x3<=x1 and x4>=x2:
    if y5<=y4 and y6>=y2 and x5<=x1 and x6>=x2:
        print("NO")
       # print("10")
    else:
        print("YES")
       # print("11")
else:
    print("YES")
   # print("12")
    