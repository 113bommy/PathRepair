import math

def mult(M1, M2, m):
    n1, n2, n3 = len(M1), len(M2), len(M2[0])
    return [[sum(M1[i][k] * M2[k][j] for k in range(n2)) % m
      for j in range(n3)] for i in range(n1)]

def matrix_pow(M, k, m):
    n = len(M)
    res = [[1 if j == i else 0 for j in range(n)] for i in range(n)]
    if k == 0:
        return res
    s = [int(c) for c in reversed(bin(k)[2:])]
    deg = M
    for c in s:
        if c: res = mult(res, deg, m)
        deg = mult(deg, deg, m)
    return res

n, k, l, m = [int(x) for x in input().split()]
if k >= (1 << l):
    res = 0
else:
    M = [[4, 2, 1],
         [0, 1, 1],
         [0, 1, 2]]
    Mpow = matrix_pow(M, (n-1)//2, m)
    v = mult(Mpow, [[0],[1],[1]], m) if n%2 else mult(Mpow, [[1],[1],[2]], m)
    a, b = v[0][0], v[1][0] + v[2][0]
    s = [(k>>i)&1 for i in range(l)]
    res = 1
    for c in s:
        res *= a if c else b
        res %= m

print(res)
