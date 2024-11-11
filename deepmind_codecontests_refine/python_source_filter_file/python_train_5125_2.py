t=int(input())
for _ in range(t):
    n,d=map(int,input().split())
    a=list(map(int,input().split()))
    i=1
    while d > 0 and i < n:
        if a[i] < d//2:
            a[0]+=a[i]
            d-=a[i]
        else:
            a[0]+=d//2
            d-=(d//2)
        i+=1
    print(a[0])