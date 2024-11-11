t=int(input())
for i in range(t):
    a=list(map(int,input().split()))
    if a[0]+a[1]+a[2]==a[6]:
        print(a[0],a[1],a[2])
    elif a[0]+a[1]+a[2]==a[6]:
        print(a[0],a[1],a[3])