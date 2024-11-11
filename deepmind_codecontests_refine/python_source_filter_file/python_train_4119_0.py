import sys
readline = sys.stdin.readline

n, x = map(int,readline().split())
tmp = list(map(float,readline().split()))
for i in range(128 - x - 1):
    tmp.append(0)

def MatM(a,b):
    c = [0 for i in range(128)]
    for i in range(127):
        for j in range(127):
                c[i ^ j] += a[i] * b[j]
    return c

def MatPow(mat,p):
    if p == 1:
        return tmp.copy()
    res = MatPow(mat, p // 2)
    newMat = MatM(res,res)
    if p & 1:
        return MatM(newMat, mat)
    return newMat
print( ('%.16f'%(1 - MatPow(tmp,n)[0])) )
