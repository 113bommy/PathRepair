class SquareMatrix():
    def __init__(self, n, mod=1000000007):
        self.n = n
        self.mat = [[0 for j in range(n)] for i in range(n)]
        self.mod = mod

    @staticmethod
    def id(n, mod=1000000007):
        res = SquareMatrix(n, mod)
        for i in range(n):
            res.mat[i][i] = 1
        return res

    @staticmethod
    def modinv(n, mod):
        assert n % mod != 0
        c0, c1 = n, mod
        a0, a1 = 1, 0
        b0, b1 = 0, 1
        while c1:
            a0, a1 = a1, a0 - c0 // c1 * a1
            b0, b1 = b1, b0 - c0 // c1 * b1
            c0, c1 = c1, c0 % c1
        return a0 % mod

    def set(self, arr):
        for i in range(self.n):
            for j in range(self.n):
                self.mat[i][j] = arr[i][j] % self.mod

    def operate(self, vec):
        assert len(vec) == self.n
        res = [0 for _ in range(self.n)]
        for i in range(self.n):
            for j in range(self.n):
                res[i] += self.mat[i][j] * vec[j]
                res[i] %= self.mod
        return res

    def add(self, other):
        assert other.n == self.n
        res = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                res.mat[i][j] = self.mat[i][j] + other.mat[i][j]
                res.mat[i][j] %= self.mod
        return res

    def subtract(self, other):
        assert other.n == self.n
        res = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                res.mat[i][j] = self.mat[i][j] - other.mat[i][j]
                res.mat[i][j] %= self.mod
        return res

    def times(self, k):
        res = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                res.mat[i][j] = self.mat[i][j] * k
                res.mat[i][j] %= self.mod
        return res

    def multiply(self, other):
        assert self.n == other.n
        res = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    res.mat[i][j] += self.mat[i][k] * other.mat[k][j]
                    res.mat[i][j] %= self.mod
        return res

    def power(self, k):
        tmp = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                tmp.mat[i][j] = self.mat[i][j]
        res = SquareMatrix.id(self.n, self.mod)
        while k:
            if k & 1:
                res = res.multiply(tmp)
            tmp = tmp.multiply(tmp)
            k >>= 1
        return res

    def trace(self):
        res = 0
        for i in range(self.n):
            res += self.mat[i][i]
            res %= self.mod
        return res

    def determinant(self):
        res = 1
        tmp = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                tmp.mat[i][j] = self.mat[i][j]
        for j in range(self.n):
            if tmp.mat[j][j] == 0:
                for i in range(j + 1, self.n):
                    if tmp.mat[i][j] != 0:
                        idx = i
                        break
                else:
                    return 0
                for k in range(self.n):
                    tmp.mat[j][k], tmp.mat[idx][k] = tmp.mat[idx][k], tmp.mat[j][k]
                res *= -1
            inv = SquareMatrix.modinv(tmp.mat[j][j], self.mod)
            for i in range(j + 1, self.n):
                c = -inv * tmp.mat[i][j] % self.mod
                for k in range(self.n):
                    tmp.mat[i][k] += c * tmp.mat[j][k]
                    tmp.mat[i][k] %= self.mod
        for i in range(self.n):
            res *= tmp.mat[i][i]
            res %= self.mod
        return res

    def transpose(self):
        res = SquareMatrix(self.n, self.mod)
        for i in range(self.n):
            for j in range(self.n):
                res.mat[i][j] = self.mat[j][i]
        return res

    def inverse(self): #self.determinant() != 0
        res = SquareMatrix.id(self.n, self.mod)
        tmp = SquareMatrix(self.n, self.mod)
        sgn = 1
        for i in range(self.n):
            for j in range(self.n):
                tmp.mat[i][j] = self.mat[i][j]
        for j in range(self.n):
            if tmp.mat[j][j] == 0:
                for i in range(j + 1, self.n):
                    if tmp.mat[i][j] != 0:
                        idx = i
                        break
                else:
                    return 0
                for k in range(self.n):
                    tmp.mat[j][k], tmp.mat[idx][k] = tmp.mat[idx][k], tmp.mat[j][k]
                    res.mat[j][k], res.mat[idx][k] = res.mat[idx][k], res.mat[j][k]
            inv = SquareMatrix.modinv(tmp.mat[j][j], self.mod)
            for k in range(self.n):
                tmp.mat[j][k] *= inv
                tmp.mat[j][k] %= self.mod
                res.mat[j][k] *= inv
                res.mat[j][k] %= self.mod
            for i in range(self.n):
                c = tmp.mat[i][j]
                for k in range(self.n):
                    if i == j:
                        continue
                    tmp.mat[i][k] -= tmp.mat[j][k] * c
                    tmp.mat[i][k] %= self.mod
                    res.mat[i][k] -= res.mat[j][k] * c
                    res.mat[i][k] %= self.mod
        return res

    def linear_equations(self, vec):
        return self.inverse().operate(vec)

L, A, B, M = map(int, input().split())

D = [0 for _ in range(18)]

for i in range(18):
    D[i] = int('9' * (i + 1)) - A) // B + 1
    D[i] = max(D[i], 0)
    D[i] = min(D[i], L)

for i in range(17)[::-1]:
    D[i + 1] -= D[i]

mat = SquareMatrix.id(3, M)

for i in range(18):
    op = SquareMatrix(3, M)
    op.mat[0][0] = 10**(i + 1)
    op.mat[0][1] = 1
    op.mat[1][1] = 1
    op.mat[1][2] = B
    op.mat[2][2] = 1
    mat = op.power(D[i]).multiply(mat)

print(mat.operate([0, A, 1])[0])
