N = int(input())
K = int(input())
ans = 1
for _ in range(N):
    num = min(ans * 2, ans + K)
print(ans)
