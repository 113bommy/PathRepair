for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    l=list(map(int,input().split()))
    l.sort(reverse=True)
    s=0
    for i in range(0,k):
        s=s+l[i]
    print(l[-1]+s)