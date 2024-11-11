t = int(input())
for _ in range(0,t):
    n = int(input())
    a = [int(i) for i in input().split()]
    nos,nob = a.count(1),a.count(2)
    if nos == nob:
        ans = 0
    else:
        s,b = 0,0
        ans = 2*n
        diff = {}
        for i in range(0,n):
            if a[i] == 1:
                s += 1
            else:
                b += 1
            diff[(s,b)] = i
            if b == s:
                ans = min(ans,2*n-i-1)
        s,b = 0,0
        for i in range(2*n-1,n-1,-1):
            if a[i] == 1:
                s += 1
            else:
                b += 1
            if (b,s) in diff:
                ans = min(ans,i-diff[b,s]-1)
            if b == s:
                ans = min(ans,i)
    print(ans)

