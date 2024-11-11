n, x = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
for i in range(n-1):
    if A[i]+A[i+1]>x:
        ans += A[i+1]+A[i]-x
        A[i+1] = max(0,x-A[i])
print(ans)