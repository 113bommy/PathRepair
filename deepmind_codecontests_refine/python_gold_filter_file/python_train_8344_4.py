MD = 10**9+7

def mult(A,B):
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i in range(len(A)):
        for j in range(len(A)):
            for k in range(len(A)):
                C[i][j] += A[i][k]*B[k][j]
            C[i][j] %= MD-1

    return C

def ex(A,k):
    n = len(A)
    R = [[0] * n for _ in range(n)]
    for i in range(n):
        R[i][i] = 1
    while k > 0:
        if k & 1:
            R = mult(R,A)
        k //= 2
        A = mult(A,A)
    return R

cma = [
    [1,1,1,1,0],
    [1,0,0,0,0],
    [0,1,0,0,0],
    [0,0,0,1,2],
    [0,0,0,0,1]
]

tri = [
    [1,1,1],
    [1,0,0],
    [0,1,0]
]

n,f1,f2,f3,c = map(int,input().split())

ce = ex(cma,n-3)
cp = ce[0][3]*2+ce[0][4]
f = ex(tri,n-3)
fp1 = f[0][2]
fp2 = f[0][1]
fp3 = f[0][0]
r = pow(f1,fp1,MD)*pow(f2,fp2,MD)*pow(f3,fp3,MD)*pow(c,cp,MD)
#print(fp1,fp2,fp3,cp)
print(r%MD)