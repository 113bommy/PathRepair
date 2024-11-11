n,m = map(int,input().split())
a = [int(x) for x in input().split()]
if n>m:
    print(0)
else:
    ans = 0
    for i in range(n):
        for j in range(i+1,n):
            ans*= abs(a[j]-a[i])
            ans%=m
    print(ans)
