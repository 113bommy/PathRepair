for _ in range(int(input())):
    x,y = list(map(int,input().split()))
    c = list(map(int,input().split()))
    for i in range(50):
        c[0] = min(c[0],c[5]+c[1])
        c[1] = min(c[1],c[0]+c[2])
        c[2] = min(c[2],c[1]+c[3])
        c[3] = min(c[3],c[2]+c[4])
        c[4] = min(c[4],c[3]+c[5])
        c[5] = min(c[5],c[4]+c[0])
    ans = 10**18
    if x>=0 and y>=0:
        ans = min(ans,c[1]*y+c[5]*x)
        mn = min(x,y)
        cost = c[0]*mn
        x-=mn
        y-=mn
        if x>=0:
            cost+=c[5]*x
        if y>=0:
            cost+=c[1]*y
        ans = min(ans,cost)
    elif x<=0 and y>=0:
        x = abs(x)
        ans = min(ans,c[2]*x+c[1]*y)
    elif x<=0 and y<=0:
        x = abs(x)
        y = abs(y)
        ans = min(ans,y*c[4]+c[2]*x)
        mn = min(x,y)
        cost = mn*c[3]
        x-=mn
        y-=mn
        if x>=0:
            cost+=x*c[2]
        if y>=0:
            cost+=y*c[4]
        ans = min(ans,cost)
    else:
        y = abs(y)
        ans = min(ans,x*c[5]+c[4]*y)
    print(ans)