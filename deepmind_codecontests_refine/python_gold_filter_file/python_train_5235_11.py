for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a=sorted(a)
    l=max(a)
    for i in range(k):
        l+=a[n-2-i]
        a[n-2-i]=0
    print(l-min(a))