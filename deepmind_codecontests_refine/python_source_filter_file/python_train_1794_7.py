n,m=[int(i) for i in input().split(" ")]
arrmv=[]
for i in range(n):
    arrmv.append([int(i) for i in input().split(" ")])
x=0
y=int(1e9+1)
sucls=[1,1]

tols=[]
mstr=""

powls=[int(pow(2,i)) for i in range(10)]
twodarray=[0  for i in range(257)]
while x+1<y:
    mid = x+(y-x)//2
    # print(x,y,mid)
    for idx,ele in enumerate(twodarray):twodarray[idx]=0
    tols.clear()
    for topidx, eletop in enumerate(arrmv):
        tmp=0
        for idx,ele in enumerate(eletop):
            if ele>=mid:tmp+=powls[idx]
        
        if not twodarray[tmp]:
            # print(eletop,tmp,mid)
            twodarray[tmp]=1
            tols.append((tmp,topidx))
    sz=len(tols)
    suc=0
    no=int(pow(2,m))
    for i in range(sz):
        for j in range(i,sz):
            if tols[i][0] | tols[j][0] == no-1:
                sucls[0],sucls[1]=tols[i][1],tols[j][1]
                # print(sucls[0],sucls[1],mid)
                suc=1;
                break;
        if suc:break
    if suc:x=mid
    else:y=mid

print(sucls[0]+1,sucls[1]+1)

