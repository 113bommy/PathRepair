n = int(input())
u = list(map(int, input().split()))
ans = 0
for i in range(1, n - 2):
    if u[i] == 0 and u[i - 1] == 1 and u[i + 1] == 1:
        ans += 1
        u[i + 1] = 0
print(ans)
