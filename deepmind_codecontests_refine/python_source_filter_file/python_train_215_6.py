n, s = map(int, input().split())
A = map(int, input().split())
A = sorted(A)
n = len(A)
res = 0
if s >= A[n//2]:
    for i in range(n//2, n):
        if s > A[i]:
            res += s-A[i]
        else:
            break
else:
    for i in range(n//2+1):
        if s < A[i]:
            res += A[i] -s
        else:
            break
print(res)