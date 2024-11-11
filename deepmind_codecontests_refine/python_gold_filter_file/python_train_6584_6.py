t = int(input())
for i in range(t):
    n,k = list(map(int,input().split()))
    ans = n
    j = 1
    if(n<=k):
        print(1)
    else:
        while(j*j<=n):
            if(n%j == 0):
                if(j <= k):
                    ans = min(ans,n//j)
                if(n//j <= k):
                    ans = min(ans,j)
            j += 1
        print(ans)