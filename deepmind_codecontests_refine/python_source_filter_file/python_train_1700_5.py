
q = int(input())

for _ in range(q):
    input()

    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    t=list(map(int,input().split()))
    d = [0] * (n+1)
    for i in range(len(a)): d[a[i]] = t[i]


    l=[0]*(n+2);l[0]=10**10
    r=[0]*(n+2);r[-1]=10**10

    for i in range(1,n+1):
        if d[i]!=0:
            l[i]=min(l[i-1]+1,d[i])
        else:
            l[i]=l[i-1]+1

    for i in range(n,0,-1):
        if d[i]!=0:
            r[i]=min(r[i+1],d[i])
        else:
            r[i]=r[i+1]+1

    for i in range(1,n+1):
        print(min(l[i], r[i]),end=" ")
    print()


