n = int(input())
A = list(map(int, input().split()))
k = sum(A) // (n * (n + 1) // 2)
d = [a1 - a2 + k for a1, a2 in zip(A, A[1:] + A[0:1])]
for di in d:
    if di < 0 or di % n:
        print('NO')
        break
else:
    print('YES')