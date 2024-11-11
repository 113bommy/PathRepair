for f in range(int(input())):
    nr,ng,nb=map(int,input().split())
    r=list(map(int,input().split()))
    g=list(map(int,input().split()))
    b=list(map(int,input().split()))
    r.sort()
    g.sort()
    b.sort()
    mi=2*(r[0]**2+g[0]**2+b[0]**2)
    fr=0
    fg=0
    fb=0
    prr=r[0]
    prg=g[0]
    prb=b[0]
    for i in range(ng):
        while r[fr]<g[i] and fr<nr-1:
            prr=r[fr]
            fr+=1
        while b[fb]<g[i] and fb<nb-1:
            prb=b[fb]
            fb+=1
        cl1=prr
        if r[fr]-g[i]<g[i]-prr:
            cl1=r[fr]
        cl2=prb
        if b[fb]-g[i]<g[i]-prb:
            cl2=b[fb]
        cur=(g[i]-cl1)**2+(g[i]-cl2)**2+(cl1-cl2)**2
        mi=min(mi,cur)
    fr=0
    fg=0
    fb=0
    prr=r[0]
    prg=g[0]
    prb=b[0]
    for i in range(nb):
        while g[fg]<b[i] and fg<ng-1:
            prg=g[fg]
            fg+=1
        while r[fr]<b[i] and fr<nr-1:
            prr=r[fr]
            fr+=1
        cl1=prr
        if r[fr]-b[i]<b[i]-prr:
            cl1=r[fr]
        cl2=prg
        if g[fg]-b[i]<b[i]-prg:
            cl2=g[fg]
        cur=(b[i]-cl1)**2+(b[i]-cl2)**2+(cl1-cl2)**2
        mi=min(mi,cur)
    fr=0
    fg=0
    fb=0
    prr=r[0]
    prg=g[0]
    prb=b[0]
    for i in range(nr):
        while g[fg]<r[i] and fg<ng-1:
            prg=g[fg]
            fg+=1
        while b[fb]<r[i] and fb<nb-1:
            prb=b[fb]
            fb+=1
        cl1=prg
        if g[fg]-r[i]<r[i]-prg:
            cl1=g[fg]
        cl2=prb
        if b[fb]-r[i]<r[i]-prb:
            cl2=b[fb]
        cur=(r[i]-cl1)**2+(r[i]-cl2)**2+(cl1-cl2)**2
        mi=min(mi,cur)
    print(mi)