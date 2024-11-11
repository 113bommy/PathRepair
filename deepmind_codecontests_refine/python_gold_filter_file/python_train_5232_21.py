for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    d={}
    for x in sorted(a):
        d[x]=len(d)
    b=[d[x] for x in a]    

    l=[0]*n
    r=[0]*n

    for x in b:
        l[x]=1
        if x-1>=0:
            l[x] += l[x-1]

    for x in b[::-1]:
        r[x]=1
        if x+1<n:
            r[x] += r[x+1]
        
    print(n-max([x+y-1 for x, y in zip(l, r)]))    