N = int(input())
ans = 0
for i in range(1, N+1):
    ans += len([j for j in range(1, i) if i % j == 0]) == 8
print(ans)
