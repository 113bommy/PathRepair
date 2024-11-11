t=int(input())
for i in range(t):
    a,b,c,d=map(int,input().split())
    x,y,x1,y1,x2,y2 = map(int, input().split())
    if not ((x1>x or x2<x or y1>y or y2<y) or (x1==x2==x and (a>0 or b>0) or y1==y2==y and (c>0 or d>0))):
        x-=a
        x+=b
        y-=c
        y+=d
        if x1<=x and x<=x2 and y1<=y and y<=y2:
            print('Yes')
        else:
            print('No')
    else:
        print('No')