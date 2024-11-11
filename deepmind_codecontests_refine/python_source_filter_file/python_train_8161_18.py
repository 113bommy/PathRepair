n,k=list(map(int,input().split()))
p=[]
a=[0]*n
for i in range(0,n):
    a[i]=k
    p.append(a)
    a[i]=1
for i in range(0,n):
    w=""
    for j in range(0,n):
        w=w+str(p[i][j])+" "
    print(w[:-1])