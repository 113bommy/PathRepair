for i in range (int(input())) :
    p,q=map(int,input().split())
    cnts,cntw=list(map(int,input().split()))
    s,w=list(map(int,input().split()))
    if s>w :
        t=s
        s=w
        w=t
        t=cnts
        cnts=cntw
        cntw=t
    ans=0
    for x1 in range (min(cnts,(p//s)+1)) :
        y1 = min(cntw,(p-x1*s)//w)
        x2 = min(cnts-x1,q//s)
        y2 = min(cntw-y1,(q-x2*s)//w)
        ans=max(ans,x1+x2+y1+y2)
    print(ans)
    