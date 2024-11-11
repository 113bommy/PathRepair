n,m=map(int,input().split())
x=[list(map(int,input().split())) for _ in range(n)]
pqr = [[1,1,1],[1,1,-1],[-1,1,-1],[1,-1,-1],[-1,-1,-1],[1,-1,1],[-1,1,1],[-1,-1,1]]
res = -10**11
for p,q,r in pqr:
    l=[]
    for i in range(n):
        l.append(p*x[i][0]+q*x[i][1]+r*x[i][2])
        l.sort(reverse=True)
        res=max(res,sum(l[:m]))
print(res)