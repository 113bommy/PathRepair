n = int(input())
A = list(map(int, input().split()))
ans = 10**50
x, y = 0, sum(A)
for i in range(n-1):
    x += A[i]
    y -= A[i]
    ans = min(ans, abs(x-y))
print(ans)
