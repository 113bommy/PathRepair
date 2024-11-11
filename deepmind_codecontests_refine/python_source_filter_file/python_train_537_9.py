t=int(input())
for i in range(t):
    n,k,d=[int(i) for i in input().split()]
    a=[int(i) for i in input().split()]
    minn=len(a[:d])
    for i in range(1,n-d+1):
        s=len(set(a[i:i+d]))
        if s<minn:
            minn=s
    print(minn)
