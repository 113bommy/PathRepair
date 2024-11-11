n,k=map(int,input().split())
z=[tuple(map(int,input().split()))for _ in range(n)]
x=[i for i,_ in z]
y=[j for _,j in z]
x.sort()
y.sort()
a=10**20
for i,l in enumerate(x):
    for r in x[i+1:]:
        for v,d in enumerate(y):
            for u in y[v+1:]:
                if sum([1for i,j in z if l<=i<=r and d<=j<=u])>=k:
                    a=min(a,(r-l)*(u-d))
print(a)