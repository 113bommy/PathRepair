t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    c=0
    for i in range(n-1):
        if abs(a[i]-a[i+1])==1:
            c=-1
    if c==0:
        print(2)
    else:
        print(1)