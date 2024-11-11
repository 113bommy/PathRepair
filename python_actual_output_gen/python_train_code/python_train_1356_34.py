n = int(input())
k = int(input())

ans = 1
for i in range(n):
    ans += min(n*2,n+k)

print(ans)