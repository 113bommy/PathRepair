n = int(input())
p = list(map(int,input().split()))
ans = 0
for i in range(n-1):
    if i+1 == p[i]:
        p[i+1] = p[i]
        ans += 1
if p[n] == n:
    ans += 1
print(ans)