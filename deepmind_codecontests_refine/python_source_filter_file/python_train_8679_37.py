n=int(input())
a=list(map(int,input().split()))
dp=[0]*(3002)
for _ in range(n):
    dp[a[_]]+=1
for _ in range(1,3002):
    if dp[_]==1:
        print(_)
        break
    