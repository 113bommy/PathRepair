L, R = map(int, input().split())
ans = 2018
for i in range(L, min(R, L+2019)+10):
    for j in range(i+1, min(R, i+2019)+10):
        ans = min(ans, i*j%2019)
print(ans)