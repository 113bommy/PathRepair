N,K=map(int,input().split())
z=[tuple(map(int,input().split()))for _ in range(N)]
x=[i for i,_ in z]
y=[j for _,j in z]
x.sort()
y.sort()
a=10**20
for i in range(N):
    for j in range(i+1,N):
        for k in range(N):
            for l in range(k+1,N):
                l,r,d,u=x[i],x[j],y[k],y[l]
                if sum([1for v,w in z if l<=v<=r and d<=w<=u else 0])>=K:
                    a=min(a,(r-l)*(u-d))
print(a)