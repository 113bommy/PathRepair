def find(A, x):
    maxi, c1, c2, c3 = 0, 0, 0, 0
    for i in range(0, len(A)):
        c11 = max([c1, 0]) + A[i]
        c22 = max([c1, c2, 0]) + A[i] * x
        c33 = max([c2, c3, 0]) + A[i]
        c1, c2, c3 = c11, c22, c33
        maxi = max([maxi, c1, c2, c3])
    return maxi

inp = lambda cast=int: list(map(cast, input().split()))
n, x = inp()
A = [0] + inp()
print(find(A, x))