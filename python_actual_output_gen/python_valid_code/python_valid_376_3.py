n = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)

ans = 0
for i in range(n-1):
    ans += A[i]

print(ans)