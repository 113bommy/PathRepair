for t in range(int(input())):
    n,m=map(int,input().split())
    a=[]
    for i in range(n):
        a.append([])
        for j in range(m):
            if i%2:
                a[i].append(("B" if j % 2 else "W"))
            else:
                a[i].append(("W" if j%2 else "B"))
    if n*m%2==0:
        if n%2==0:
            a[-1][0]="B"
        else:
            a[-1][-1]="B"
    for i in a:
        print(*i,sep="")