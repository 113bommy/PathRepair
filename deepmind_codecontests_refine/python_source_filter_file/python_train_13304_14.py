l,r = map(int,input().split())
r = min(r, l+4038)
ans = 2018
for i in range(l,r):
    for j in range(l+1,r+1):
        if ans > i*j%2019:
            ans = i*j%2019
print(ans)