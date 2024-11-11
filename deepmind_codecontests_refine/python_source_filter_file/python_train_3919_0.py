n=int(input())
nfirst,rc,bc,memr,memb,memg,dr,db,s,rl,bl,gl,lg=13*[0]
for i in range(n):
    a=input().split(" ")
    if a[1]=="G":
        if memg==0:
            gl=int(a[0])
        if nfirst:
            if memr>0:
                dr=max(dr,int(a[0])-memr)
            if memb>0:
                db=max(db,int(a[0])-memb)
            s+=min(2*(int(a[0])-memg),3*(int(a[0])-memg)-dr-db)
        dr,db,rc,bc=4*[0]
        memr,memb,memg=3*[int(a[0])]
        nfirst=True
        gl+=1
    elif a[1]=="R":
        rc+=1
        if memr==0:
            rl=int(a[0])
        if memr>0 and nfirst:
            dr=max(dr,int(a[0])-memr)
        memr=int(a[0])
    elif a[1]=="B":
        bc+=1
        if memb==0:
            bl=int(a[0])
        if memb>0 and nfirst:
            db=max(db,int(a[0])-memb)
        memb=int(a[0])
if lg>0:
    if rc>0:
        s+=memr-memg
    if bc>0:
        s+=memb-memg
    if rl>0:
        s+=gl-rl
    if bl>0:
        s+=gl-bl
else:
    s+=memr-rl+memb-bl
print(s)