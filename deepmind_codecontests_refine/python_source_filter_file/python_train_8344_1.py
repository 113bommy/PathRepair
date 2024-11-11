def mat_mul(a, b):
    n, m, p = len(a), len(b), len(b[0])
    res = [[0]*p for _ in range(n)]

    for i in range(n):
        for j in range(p):
            for k in range(m):
                res[i][j] += a[i][k]*b[k][j]
            res[i][j] %= 1000000007

    return res

def mat_pow(a, n):
    if n == 1: return a
    if n%2 == 1: return mat_mul(mat_pow(a, n-1), a)
    t = mat_pow(a, n//2)
    return mat_mul(t, t)

n, f1, f2, f3, c = map(int, input().split())


m1 = [[3, 1000000005, 0, 1000000006, 1], [1, 0, 0, 0, 0], [0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 1, 0]]
m2 = [[2], [0], [0], [0], [0]]
t1 = pow(c, mat_mul(mat_pow(m1, n), m2)[-1][0], 1000000007)

m1 = [[0, 0, 1], [1, 0, 1], [0, 1, 1]]
m2 = [[1], [0], [0]]
m3 = mat_mul(mat_pow(m1, n-1), m2)
t2 = pow(f1, m3[0][0], 1000000007)
t3 = pow(f2, m3[1][0], 1000000007)
t4 = pow(f3, m3[2][0], 1000000007)

print(t1*t2*t3*t4%1000000007)
