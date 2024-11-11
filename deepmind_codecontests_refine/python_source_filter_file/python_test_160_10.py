for _ in range(int(input())):
    n,m,rx,ry,dx,dy=list(map(int,input().split()))
    cnt=0
    p1=1
    p2=1
    while rx!=dx and ry!=dy:
        if rx==n:
            p1=-p1
        elif ry==m:
            p2=-p2
        rx+=p1
        ry+=p2
        cnt+=1
    print(cnt)