na, nb = [int(x) for x in input().split()]
k, m = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

print('YES' if A[k-1] < B[m-len(B)] else 'NO')
