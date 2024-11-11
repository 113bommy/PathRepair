for i in ' '*int(input()):
    a,b,c,d=map(int,input().split())
    u,v,x1,y1,x2,y2=map(int,input().split())
    x=b-a
    y=d-c
    if x1>x or x2<x or y1>y or y2<y:
        print('No')
        continue
    if x==0 and a:
        if u==x1==x2:
            print('No')
            continue
    if y==0 and c:
        if v==y1==y2:
            print('No')
            continue
    print('Yes')