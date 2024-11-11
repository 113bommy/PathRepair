n=int(input())
a=list(map(int,input().split()))
if len(set(a))==n:
    a.append(n)
    print(*a)
else:
    a.insert(0,0)
    s=str(n)
    x=n
    b=[n]
    while x!=1:
        b.append(a[x-1])
        x=a[x-1]
    print(b[::-1])