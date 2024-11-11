class Edge:
    def __init__(self,a,b,c):
        self.l=a
        self.r=b
        self.v=c

inf=list(map(int,input().split()))
n=inf[0]
m=inf[1]
k=inf[2]
check=[False]*(n+2)
edges=[None]*m
for i in range(m):
    inf=list(map(int,input().split()))
    edges[i]=Edge(inf[0],inf[1],inf[2])
    
ans=77777777888
if k>0:
    inf=list(map(int,input().split()))
    for i in inf:
        check[i]=True
        
for e in edges:
    f=0
    if check[e.l]:
        f+=1
    if check[e.r]:
        f+=1
    if f==1:
        if e.v<ans:
            ans=e.v
            
if ans==77777777888:
    print(-1)
else:
    print(ans)