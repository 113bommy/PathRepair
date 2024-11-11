for i in range(int(input())):
    a,b,c,d=map(int,input().split())
    x,y,x1,y1,x2,y2=map(int,input().split())
    e=b-a
    f=d-c
    g=0
    if(a>0 and b>0):
        if(x1<=x-min(1,a)<=x2 or x1<=x+min(1,b)<=x2):
            pass
        else:
            g=-1
    if(c>0 and d>0):
        if(y1<=y-min(1,c)<=y2 or y1<=y+min(1,d)<=y2):
            pass
        else:
            g=-1
    if(g==-1):
        print("NO")
    else:
        x=x+e
        y=y+f
        if(x1<=x<=x2 and y1<=y<=y2):
            print("YES")
        else:
            print("NO")
