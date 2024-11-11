N = int(input())
ans = 0
for i in range(1, N+1, 2):
    ans += len([j for j in range(1, i+1) if i % j == 0]) == 8
print(ans)
