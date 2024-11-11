
n,k = map(int,input().split())
ans = []
for i in range(1,2*n+1):
    ans.append(i)

for i in range(0,k,2):
    ans[i],ans[i+1] = ans[i+1],ans[i]

print(*ans)
