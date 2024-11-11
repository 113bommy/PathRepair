n,m=map(int,input().split())
if (n==1 and m==1):
    print('0')
else:
    masst=[]
    mchisel=[]
    for i in range(101):
        masst.append(2**i)

    for j in range(101):
        summ=0
        for i in range(101-j):
            summ+=masst[i]
        for i in range(101-j-1):
            mchisel.append(summ-masst[i])
    mchisel.sort()

    minn=0
    minx=1000000000000000000000000000000000000000000
    maxn=0
    maxn1=1000000000000000000000000000000000000000000
    for i in mchisel:
        if abs(n-i)<minx and i>=n:
            minx=abs(n-i)
            minn=i
    for i in mchisel:
        if abs(m-i)<maxn1 and i<=m:
            maxn1=abs(m-i)
            maxn=i
    z=mchisel.index(minn)
    z1=mchisel.index(maxn)
    print(z1-z+1)