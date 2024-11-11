t=int(input())
for i in range(t):
    W,H=map(int,input().split())
    a,b,c,d=map(int,input().split())
    w,h=map(int,input().split())
    if abs(a-c)+w>W and abs(b-d)+h>H:
        print(-1)
    elif abs(a-c)+w>W and abs(b-d)+h<=H:
        if H-d>b:
            if H-d>=h:
                print(0)
            else:
                print(h-H+d)
        else:
            if b>=h:
                print(0)
            else:
                print(h-b)
    elif abs(a-c)+w<=W and abs(b-d)+h>H:
        if W-c>a:
            if W-c>=w:
                print(0)
            else:
                print(w-W+c)
        else:
            if a>=w:
                print(0)
            else:
                print(w-a)
    else:
        if H-d>b:
            if H-d>=h:
                ht=0
            else:
                ht=h-H+d
        else:
            if b>=h:
                ht=0
            else:
                ht=h-b
        if W-c>a:
            if W-c>=w:
                wd=0
            else:
                wd=w-W+c
        else:
            if a>=w:
                wd=0
            else:
                wd=w-a
        print(min([h,w]))
