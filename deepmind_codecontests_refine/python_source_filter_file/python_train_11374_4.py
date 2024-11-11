def solve(n,m):
    ans=0
    s=[list(map(int,input().split())) for _ in range(n)]
    diag_num=n+m-1
    for i in range(diag_num//2):
        sum=0
        for j in range(i+1):
            k=i-j
            if 0<=j<n and 0<=k<m :
                sum+=s[j][k]
        i2=diag_num-i-1
        for j in range(i2):
            k=i2-j
            if 0<=j<n and 0<=k<m :
                sum+=s[j][k]
        y=min(i+1,n)
        ans+=min(sum,2*y-sum)
    print(ans)

for _ in range(int(input())):
    n,m=map(int,input().split())
    solve(n,m)

