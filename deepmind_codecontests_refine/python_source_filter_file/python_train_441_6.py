
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))

    p=[]
    p.append(a[0])
    for i in range(1,n):
        if i==n-1:
            if a[i]!=p[i-1] and a[i]!=p[0]:
                p.append(a[i])
            elif b[i]!=p[i-1] and b[i]!=p[0]:
                p.append(b[i])
            else:
                p.append(c[i])
        else:
            if a[i]!=p[i-1]:
                p.append(a[i])
            else:
                p.append(b[i])

    print(p)