N, X, D = map(int, input().split())
if D == 0:
    r = N*(X!=0)+1
else:
    if D < 0:
        X,D=-X,-D
    d=dict()
    for k in range(N+1):
        M = (k*X)%D
        F = (k*X)//D + ((k-1)*k)//2 #(1..k-1)
        L = (k*X)//D + (2*N-k-1)*k//2# (N-k..N-1)
        if M not in d:
            d[M] = list()
        d[M].append((F,-1))
        d[M].append((L,1))
    r = 0
    for m in d:
        fc=f=0
        for x in sorted(d[m]):
            r+=(x[0]-f+1)*(fc<2)*(x[1]>0)
            fc-=x[1]
            f=(fc==1)*x[0]*(x[1]<0)+f*(x[1]>0 or fc!=1)
print(r)