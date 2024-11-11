n,I=map(int,input().split())
print(n,I)
a=list(map(int,input().split()))
I*=8
k=I//n
if k>=20:
    res=0
else:
    K=2**k
    print(K,I)
    cc={}
    for ai in a:
        cc[ai]=cc.get(ai,0)+1
    pres=[]
    dd=sorted(cc)
    for i in dd:
        pres.append(cc[i])
    for i in range(1,len(pres)):
        pres[i]+=pres[i-1]
    if K>=len(pres):
        res=0
    else:
        mm=0
        for i in range(K,len(pres)):
            if mm<pres[i]-pres[i-K]:
                mm=pres[i]-pres[i-K]
        res=n-mm
print(res)