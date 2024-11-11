t = int(input())
for _ in range(t):
    n,k = map(int,input().strip().split())
    ls = list(map(int,input().strip().split()))
    ans = ls[0]
    for i in range(1,n):
        if ls[i]*i<=k:
            temp = ls[i]
            k -= temp*i
            ans += temp
        elif i<=k:
            temp = k//i
            k -= temp*i
            ans += temp
        else:
            break
        if k==0:
            break
    print(ans)
            
