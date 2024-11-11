n=int(input())
a=list(map(int,input().split()))
b=[a]
for x in range(n-1):
    b.append([])
    m=min(a)
    y=len(a)-1
    while y>=0 and a[y]!=m:
        b[-1].append(a[y])
        y-=1
    y-=1
    while y>=0:
        b[-1].append(a[y])
        y-=1
    a=b[-1][::-1]
m=int(input())
for x in range(m):
    k,l=map(int,input().split())
    if k<n:
        k=n-(k-1)-1
        l=len(b[k])-(l-1)-1
        print(b[k][l])
    else:
        print(b[0][l-1])
