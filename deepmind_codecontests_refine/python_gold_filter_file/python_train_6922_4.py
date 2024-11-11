na, nb = [int(x) for x in input().split()]
k, m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

if A[k - 1] < B[len(B) - m]:
    print('YES')
else:
    print('NO')