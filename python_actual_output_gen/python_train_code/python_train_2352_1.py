for _ in range(int(input())):
    s=input()
    d=set()
    x,y = 0,0
    ans=0
    for i in s:
        cx,cy = x,y
        if i=='N':
            x,y = x,y+1
        elif i=='S':
            x,y = x,y-1
        elif i=='E':
            x,y = x+1,y
        elif i=='W':
            x,y = x-1,y
        tp = tuple(sorted([cx,cy,x,y]))
        if tp in d:
            ans+=1
        else:
            ans+=5
            d.add(tp)
    print(ans)