import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n,sa,sb,da,db=map(int,input().split());e={};g=0
    if 2*da>=db:exec((n-1)*'input();');print("Alice");continue
    for i in range(n):e[i]=[]
    for i in range(n-1):u,v=map(int,input().split());e[u-1]+=[v-1];e[v-1]+=[u-1]
    s=[];d=[[None]*2+[0]*2 for i in range(n)];q=[(0,-1)]
    while q:
        v,p=q.pop()
        if v==sa-1:d[v][0]=0
        elif v==sb-1:d[v][1]=0
        if v<1 or len(e[v])>1:
            s.append((v,p))
            for i in e[v]:
                if i!=p:q.append((i,v))
    while s:
        v,p=s.pop()
        m=[0,0];b=0
        for i in e[v]:
            if i!=p:
                w=d[i][2]
                if w>m[0]:m=[w,m[0]]
                elif w>m[1]:m=[m[0],w]
                b=max(b,d[i][3])
                w=d[i][0]
                if w!=None:d[v][0]=w+1
                w=d[i][1]
                if w!=None:d[v][1]=w+1
        d[v][2]=m[0]+1;d[v][3]=max(min(2,len(e[v])-(v>0))+sum(m),b)
        if g<1 and d[v][0]!=None and d[v][1]!=None:g=d[v][0]+d[v][1]
    print(["Alice","Bob"][g>da and d[0][3]>2*da])