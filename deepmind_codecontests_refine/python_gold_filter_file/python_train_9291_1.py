t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a=[[0]*(n) for j in range(n)]
    c=[[0]*(n) for j in range(n)]
    x=0
    y=0
    d=dict()
    p=0
    while(k!=0):
        if (x%n,y%n) in d.keys():
            x=0
            y=p+1
            p+=1


        a[x%n][y%n]=1
        d[(x % n, y % n)] = 1
        x+=1
        y+=1

        k+=-1
    for p in range(n):
        for j in range(n):
            c[p][j]=a[j][p]
    min1=10**5+1
    max1=-1
    min2=10**5+1
    max2=-1
    for i in range(n):
        min1=min(min1,a[i].count(1))
        max1=max(max1,a[i].count(1))
        min2 = min(min2, c[i].count(1))
        max2 = max(max2, c[i].count(1))
    k=int((max1-min1)**2)+int(max2-min2)**2
    print(k)

    for j in a:
        for q in j:
            print(q,end="")
        print()








