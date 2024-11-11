t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    if(sorted(a) == a):
        print(0)
        continue
    l = 0
    r = n-1
    ll = 1
    rr = n
    while l < len(a) and a[l] == ll:
        ll+=1
        l+=1
    while r > -1 and a[r] == rr:
        rr-=1
        r-=1
    flag = 0
    for i in range(l,r+1):
        if a[l]==l+1:
            flag = 1
    print(1 if not flag else 2)