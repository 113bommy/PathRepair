n,m = map(int,input().split())
house = list(map(int,input().split()))
ans = 0
i=1
for h in house:
    diff = h-i
    if diff >=0:
        ans+=diff
    else:
        ans+=n-diff
    i=h
print(ans)