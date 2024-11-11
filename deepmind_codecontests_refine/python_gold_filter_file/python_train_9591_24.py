def ans(b):
    for i in range(n):
        if (b+k*i)<=n:
            lo.append((b+k*i)-1)
        if (b-k*i)>0:
            lo.append((b-k*i)-1)
    l1=l[:]
    k1=0
    k2=0
    for i in lo:
        l1[i]=0
    k1=l1.count(1)
    k2=l1.count(-1)
    ge.append(abs(k1-k2))
n,k=map(int,input().split())
l=list(map(int,input().split()))
lo=[]
ge=[]
for i in range(1,k+1):
    ans(i)
    lo=[]
print(max(ge))
