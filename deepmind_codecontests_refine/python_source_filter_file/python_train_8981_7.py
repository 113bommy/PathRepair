t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    b=[]
    for j in range(n):
        b.append(list(map(int,input().split())))

    s=0
    mi=float("inf")
    f=0
    for w in range(n):
        for j in range(m):
            s+=abs(b[w][j])
            if b[w][j]<0:
                f=1
            mi=min(mi,abs(b[w][j]))

    if f==0:
        print(s)
    else:
        print(s-2*mi)





