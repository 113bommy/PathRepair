def nod(n, m):
    if(m==0):
        return n;
    if(n>m):
        return nod(m,n%m);
    else:
        return nod(n,m%n);

n=input();
x = sorted(list(map(int, input().split())))
m = min(x)
nnod=0
for i in range(len(x)):
    if(i>1):
        if(i==2):
            nnod=nod(x[i]-x[i-1], x[i-1]-x[i-1])
        else:
            nnod=nod(nnod, x[i]-x[i-1])
res=0
for i in range(len(x)):
    if(i>0):
        res+=(x[i]-x[i-1])/nnod - 1;
print(int(res))