n = int(input())
A = list(map(int,input().split()))

A.sort(reverse=True)

ans = A[0]
for i in range(1,n-1):
    ans += A[(i//2) + 1]

print(ans)