for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    r,q=0,a[-1]
    for i in range(n-2,-1,-1):
        if a[i]<q:q=a[i]
        else:r+=1
    print(r)