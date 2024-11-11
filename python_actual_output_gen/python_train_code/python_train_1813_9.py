
for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a=sorted(a)
    l=max(a)
    for i in range(k):
        l+=a[i]
        a[i]=0
    print(l-min(a))