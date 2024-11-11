for _ in range(int(input())):
    n,k=map(int,input().split())
    ar=list(map(int,input().split()))
    val=abs(min(ar)+k)
    ar1=[val]*n
    ans=0
    for i in range(n):
        if abs(ar[i]-ar1[i])<=k:
            ans=val
        else:
            ans=-1
            break
    print(val)      