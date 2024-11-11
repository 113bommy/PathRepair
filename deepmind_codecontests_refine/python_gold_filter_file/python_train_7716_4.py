n, k = map(int, input().split())

A = []

for i in range(30, -1, -1):
    if (n >= (1<<i)):
        n-=(1<<i)
        A.append((1<<i))

for i in range(k):
    while (len(A) < k and i < len(A) and A[i] > 1):
        A.append(A[i]//2)
        A[i]//=2

if (len(A) != k):
    print('NO')
else:
    print('YES')
    print(*A)
