n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(1, n - 1):
    if A[i] == 0 and A[i - 1] == 1 and A[i + 1] == 1:
        ans += 1
        A[i + 1] = 0
print(ans)
