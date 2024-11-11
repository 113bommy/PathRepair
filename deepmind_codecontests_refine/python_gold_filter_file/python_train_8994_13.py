n,m=list(map(int,input().split()))
if m:
    
    d=list(map(int,input().split()))
    d.sort()
    if d[0]==1 or d[-1]==n:
        print('NO')
    else:
        g=0
        f=1
        for i in range(1,m):
            if d[i]-d[i-1]==1:
                g=g+1
            else:
                g=0
            if g>=2:
                f=0
                break
        if f:
            print('YES')
        else:
            print('NO')
            
else:
    print('YES')