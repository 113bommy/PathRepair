while 1:
    M,T,P,R=map(int,input().split())
    if not M and not T and not P and not R:break
    d={i:[0,0] for i in range(1,T+1)}
    wa=[[0 for _ in range(P)] for _ in range(T)]
    for _ in range(R):
        m,t,p,j=map(int,input().split())
        if j:
            wa[t-1][p-1]+=20
        else:
            d[t][0]+=1
            d[t][1]+=(m+wa[t-1][p-1]) 
    rank=sorted(d.items(),key=lambda x:(x[1][0],-x[1][1]),reverse=True)        
    f=lambda x:"=".join(sorted(x,key=lambda y:int(y),reverse=True))
    l=[]
    b=[]
    for (i,j) in enumerate(rank):
        if i>0 and rank[i][1]!=rank[i-1][1]:
            l.append(f(b))
            b=[]
        b.append(str(j[0]))
    if b:l.append(f(b))
    print ",".join(l)

