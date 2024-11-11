for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    y=sorted(l)
    x=min(l)
    a=[]
    b=[]
    for i in range(n):
        if i%x==0:
            a.append(l[i])
            b.append(i)
    a.sort()
    for i in range(len(b)):
        l[b[i]]=a[i]
    if(l==y):
        print('YES')
    else:
        print('NO')
    