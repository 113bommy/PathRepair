x=input()
chap=0
bala=0
if len(x)%2==1:
    print(-1)
else:    
    for i in range(len(x)):
        if x[i]=='R':
            chap-=1
        elif x[i]=='L':
            chap+=1
        elif x[i]=='U':
            bala+=1
        else:
            bala-=1
    if bala<0:
        bala= -bala
    elif chap<0:
        chap= -chap
    r=min(chap,bala)
    chap=chap-r
    bala=bala-r
    if chap==0:
        z=bala
    elif bala==0:
        z=chap
    print(z//2 + r)
