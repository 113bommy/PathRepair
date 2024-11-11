n = int(input())
A = []
B = []
for _ in range(n):
    v1, v2 = list(map(int, input().split(' ')))
    A.append(v1)
    B.append(v2)

A.sort()
B.sort()

if n % 2:
    print(B[n//2] - A[n//2] + 1)
else:
    print((B[n//2]+B[n//2-1]) - (A[n//2]+A[n//2-1]) + 1)