t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))[:n]
    b=list(map(int,input().split()))[:n]
    b_min=min(b)
    a_min=min(a)
    res=0
    for i in range(n):
        if a[i]-a_min>b[i]-b_min:
            res+=b[i]-b_min
        elif a[i]-a_min<=b[i]-b_min:
            res+=a[i]-a_min
    print(res)