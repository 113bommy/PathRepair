t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if a[0]+a[1]<=a[n-1]:
        print(0,1,n-1)
    else:
        print(-1)
