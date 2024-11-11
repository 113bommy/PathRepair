n,pos,maxx,que=list(map(int,input().split()))
initial=[1]*n
for x in range(que):
    a,b=list(map(int,input().split()))
    if a==1:
        lam=b-1
        if pos<lam:
            pass
        else:
            pos+=1
        initial.insert(lam,1)
        n+=1
        print(n,pos)
    else:
        jam=b
        ham=b+1
        if pos<=jam:
            initial=initial[0:jam]
            n=len(initial)
        else:
            initial=initial[ham-1:]
            n=len(initial)
            pos-=jam
        print(n,pos)
            