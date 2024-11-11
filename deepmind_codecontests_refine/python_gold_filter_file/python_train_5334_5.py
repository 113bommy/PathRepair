t=int(input())
for _ in range(t):
    l,r,d,up=map(int,input().split())
    
    u,v,x1,y1,x2,y2=map(int,input().split())
    if x1==x2 and (l>0 or r>0):
        print('NO')
        continue
    if y1==y2 and (d>0 or up>0):
        print('NO')
        continue
    if l>r:
        l=l-r
        r=0
    else:
        r=r-l
        l=0
    if d>up:
        d=d-up
        up=0
    else:
        up=up-d
        d=0
    #print(l,r,d,up)
    if l>r:
        if u-l>=x1:
            u=u-l
        else:
            print('NO')
            continue
    else:
        if u+r<=x2:
            u=u+r
        else:
            print('NO')
            continue
    #print(u)
    if up>d:
        if v+up<=y2:
            v=v+up
        else:
            print('NO')
            continue
    else:
        if v-d>=y1:
            v=v-d
        else:
            print('NO')
            continue
    #print(v)
    print('YES')
        
            
    t-=1
