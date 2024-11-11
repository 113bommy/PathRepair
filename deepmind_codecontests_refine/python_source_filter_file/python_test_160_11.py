t =int(input())
for _ in range(t):
    n,m,rb,cb,rd,cd = map(int, input().split())
    r = rb
    c = cb
    dr=1
    dc=1
    time = 0
    while(True):
        #check
        if r==rd or c==cd:
            break;
        rr=r+dr
        cc=c+dc
        if (rr<1 or rr>m):
            dr*=-1
        if (cc<1 or cc>m):
            dc*=-1
        r = r+dr
        c = c+dc
        time+=1
    print(time)




