for _ in range(int(input())):
    a,b,c,d = map(int, input().split())
    x,y,x1,y1,x2,y2=map(int,input().split())
    if x1<=x-a+b<=x2 and y1<=y-c+d<=y2:
        if (x1==x==x2 and a+b!=0) or (y1==y==y2 and c+b!=0):
            print('NO')
        else: print('YES')
    else: print('NO')
