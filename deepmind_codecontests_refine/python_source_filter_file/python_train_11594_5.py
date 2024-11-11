x,y=map(int,input().split())
dp=[]
dp.append(0)
dp.append(1)

n=2
while 1:
    sm=0
    for k in range(n-1,n-y-1,-1):
        if k==0:
            break
        sm+=dp[k]
    if sm>=x:
        break
    dp.append(sm)
    n+=1

dp.reverse()
res=[]

n=0
while n<len(dp) and x>=0:
    if x>=dp[n]:
        res.append(dp[n])
        x-=dp[n]
    n+=1

print(len(res))
print(*res)

