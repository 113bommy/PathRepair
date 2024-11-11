n,s=map(int,input().split())
sell={}
buy={}
lb=[]
ls=[]
ks=0
kb=0
for _ in range(n):
    d,p,q=map(str,input().split())

    if d=="B":
        
        if d+p in buy:
            buy[d+p]+=int(q)
        else:
            lb.append(int(p))
            buy[d+p]=int(q)
    else:
        
        if d+p in sell:
            sell[d+p]+=int(q)
        else:
            ls.append(int(p))
            ks+=1
            sell[d+p]=int(q)
ls.sort()
lb.sort()
k=0
for i in range(min(ks,s)-1,-1,-1):
    print("S",ls[i], sell["S"+str(ls[i])])
k=0
for x in lb:
    if k<s:
        print("B",x,buy["B"+str(x)])
    else:
        break
    k+=1