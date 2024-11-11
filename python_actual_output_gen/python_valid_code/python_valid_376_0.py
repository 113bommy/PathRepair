n = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)

ans = 0
for i in range(1, n):
    ans += A[i-1]
print(ans)
