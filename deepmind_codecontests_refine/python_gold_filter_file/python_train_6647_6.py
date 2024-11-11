N = int(input())
*A, = map(int, input().split())
C = sum(A)
if C % (N*(N+1)//2) == 0:
    k = C // (N*(N+1) // 2)
    B = [A[i-1] - A[i] + k for i in range(N)]
    ok = 1
    for b in B:
        if b < 0 or b % N > 0:
            ok = 0
            break
    if ok:
        print('YES')
        exit(0)
print('NO')
