t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a=[int(v) for v in input().split()]
    p=min(a)
    q=max(a)
    for j in range(n):
        a[j]=q-a[j]
    if k%2==0:
        for j in range(n):
            a[j]=a[j]-(q-p)
    print(' '.join(map(str,a)))