L,R = map(int, input().split())
R = min(R, L+4038)
ans = 2018
for i in range(L,R):
    for j in range(i+1,R):
        x = (i*j)%2019
        ans = min(ans,x)
print(ans)