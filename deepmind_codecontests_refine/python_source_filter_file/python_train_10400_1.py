def func(n,k):
    SUM = 0
    ans = 0
    A = [int(input()) for _ in range(n)]
    for i in range(k-1):
        SUM += A[i]
    for i in range(k,len(A)):
        ans = max(ans,SUM+A[i]-A[i-k])
        SUM = SUM+A[i]-A[i-k]
    print(ans)

for _ in range(10)
    n,k = [int(s) for s in input().split()]
    if n == 0 and k ==0:
        break
    else:
        func(n,k)
