N,x = map(int,input().split())
A = list(map(int,input().split()))
ans = 0
for i in range(1,N):
    cnt = A[i-1] + A[i] - x
    if cnt > 0:
        A[i] = max(0,x-A[i])
        ans += cnt
print(ans)