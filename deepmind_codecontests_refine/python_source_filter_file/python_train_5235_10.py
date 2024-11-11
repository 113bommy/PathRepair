for _ in range(int(input())):
    n,k=map(int,input().split())
    a=sorted(map(int,input().split()))
    i=0
    while k and i<n-1:
        a[-1]+=a[i]
        a[i]=0
        i+=1; k-=1
    print(a[-1])