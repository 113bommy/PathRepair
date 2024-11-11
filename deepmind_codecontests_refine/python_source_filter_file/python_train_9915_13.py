t=int(input())
for _ in range(t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    b=[0]*n
    for i in range(1,n-1):
        if a[i]>a[i-1] and a[i]>a[i+1]:
            b[i]=1
    c=b[:k-1].count(1)
    d=[]
    d.append([c,0])
    for i in range(1,n-k+1):
        if b[i]==1:
            c=c-1
        if b[i+k-2]==1:
            c=c+1
        d.append([c,-1*(i+1)])
    e=max(d)
    print(e[0]+1,e[1]*-1)