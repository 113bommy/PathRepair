for i in range(int(input())):
    x1,y1,x2,y2 = map(int,input().split())
    count =0
    if(x1>x2):
        d1 = x1-x2
    else:d1 = x2-x1
    if(y1>y2):d2 = y1-y2
    else:d2 =y2-y1
    if(d2!=0 and d1 !=0 ):
        count = d1+2+d2
    else:count = d1+d2
    print(count)
    