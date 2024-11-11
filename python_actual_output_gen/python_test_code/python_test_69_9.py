n, k = map(int, input().split())
A = list(map(int, input().split()))
if k == n - 1:
    ans = max(A)
else:
    ans = A[0]
    cnt = 0
    for i in range(n):
        if ans > A[i]:
            cnt += 1
            if cnt == k:
                break
        else:
            ans = A[i]
            cnt = 1
print(ans)
