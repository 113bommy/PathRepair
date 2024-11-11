
t = int(input())

for _ in range(t):
    w,h = map(int,input().split())
    x1,y1,x2,y2 = map(int,input().split())
    w2,h2 = map(int,input().split())
    ans = 50000
    ans2 = 50000
    c=0
    if(w-(x2-x1) >= w2):
        if(x1 > w-x2):
            if(x1 >= w2):
                print(0)
                continue
            else:
                ans = abs(x1 - w2)
        else:
            if(w-x2 >= w2):
                print(0)
                continue
            else:
                ans = abs(w2-(w-x2))
    else:
        c+=1
    if(h-(y2-y1) >= h2):
        if(y1 > h-y2):
            if(h2<=y1):
                print(0)
                continue
            else:
                ans2 = abs(y1 - h2)
        else:
            if(h-y2 >= h2):
                print(0)
                continue
            else:
                ans2 = abs(h2-(h-y2))
    else:
        if(c==1):
            print(-1)
            continue
    print(min(ans,ans2))
