t=int(input())
for case in range(t):
    n,r=map(int,input().split())
    arr=list(map(int,input().split()))
    f=True
    for x in arr:
        if x!=r:
            f=False
            break
    if f:
        print(0)
        continue
    if sum([arr[x]-r for x in range(n)])==0 or arr.count(r)==n-1:
        print(1)
        continue
    print(2)