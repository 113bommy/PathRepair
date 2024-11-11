n = int(input())
A = list(map(int, input().split()))
s, t = sum(A), n * (n + 1) // 2
if s % t != 0:
    print('NO')
else:
    k = s // t
    D = [A[i+1] - A[i] for i in range(n-1)] + [A[0] - A[-1]]
    D = [d - k for d in D]
    print('YES' if all((d == 0 or d % n == 0 for d in D)) else 'NO')
