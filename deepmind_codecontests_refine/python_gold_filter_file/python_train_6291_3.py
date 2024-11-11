n = int(input())
lis = list(map(int,input().split()))
ans = 1e18
for i in lis:
    tmp = list(map(int,input().split()))
    totalTime = 0
    for j in tmp:
        totalTime += j*5
    totalTime+=len(tmp)*15
    if min(ans,totalTime)==totalTime:
        ans = totalTime
print(ans)