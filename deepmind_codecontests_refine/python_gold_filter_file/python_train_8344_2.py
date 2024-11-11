fib_matrix = [[1,1,1],
              [1,0,0],
              [0,1,0]]

def matrix_square(A, mod):
    return mat_mult(A,A,mod)


def mat_mult(A,B, mod):
  if mod is not None:
    return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0]+A[0][2]*B[2][0])%mod, (A[0][0]*B[0][1] + A[0][1]*B[1][1]+A[0][2]*B[2][1])%mod,(A[0][0]*B[0][2] + A[0][1]*B[1][2]+A[0][2]*B[2][2])%mod],
            [(A[1][0]*B[0][0] + A[1][1]*B[1][0]+A[1][2]*B[2][0])%mod, (A[1][0]*B[0][1] + A[1][1]*B[1][1]+A[1][2]*B[2][1])%mod,(A[1][0]*B[0][2] + A[1][1]*B[1][2]+A[1][2]*B[2][2])%mod],
           [(A[2][0]*B[0][0] + A[2][1]*B[1][0]+A[2][2]*B[2][0])%mod, (A[2][0]*B[0][1] + A[2][1]*B[1][1]+A[2][2]*B[2][1])%mod,(A[2][0]*B[0][2] + A[2][1]*B[1][2]+A[2][2]*B[2][2])%mod]]


def matrix_pow(M, power, mod):
    #Special definition for power=0:
    if power <= 0:
      return M

    powers =  list(reversed([True if i=="1" else False for i in bin(power)[2:]])) #Order is 1,2,4,8,16,...

    matrices = [None for _ in powers]
    matrices[0] = M

    for i in range(1,len(powers)):
        matrices[i] = matrix_square(matrices[i-1], mod)


    result = None

    for matrix, power in zip(matrices, powers):
        if power:
            if result is None:
                result = matrix
            else:
                result = mat_mult(result, matrix, mod)

    return result
fib_matrix2 = [[1,1,1,1,0],
              [1,0,0,0,0],
              [0,1,0,0,0],
              [0,0,0,1,1],
              [0,0,0,0,1]]

def matrix_square2(A, mod):
    return mat_mult2(A,A,mod)


def mat_mult2(A,B, mod):
  if mod is not None:
    m=[]
    for i in range(5):
      m.append([])
      for j in range(5):
        sums=0
        for k in range(5):
          sums+=A[i][k]*B[k][j]
        m[-1].append(sums%mod)
    return m
def matrix_pow2(M, power, mod):
    #Special definition for power=0:
    if power <= 0:
      return M

    powers =  list(reversed([True if i=="1" else False for i in bin(power)[2:]])) #Order is 1,2,4,8,16,...

    matrices = [None for _ in powers]
    matrices[0] = M

    for i in range(1,len(powers)):
        matrices[i] = matrix_square2(matrices[i-1], mod)


    result = None

    for matrix, power in zip(matrices, powers):
        if power:
            if result is None:
                result = matrix
            else:
                result = mat_mult2(result, matrix, mod)

    return result
n,f1,f2,f3,c=map(int,input().split())
f3pow=matrix_pow(fib_matrix, n-2, 1000000006)[0][2]
f1pow=matrix_pow(fib_matrix, n-2, 1000000006)[1][2]
f2pow=matrix_pow(fib_matrix, n-2, 1000000006)[1][1]
cpow=2*matrix_pow2(fib_matrix2, n, 1000000006)[2][4]
ans=pow(c,cpow,1000000007)
ans=(ans*pow(f1,f1pow,1000000007))%1000000007
ans=(ans*pow(f2,f2pow,1000000007))%1000000007
ans=(ans*pow(f3,f3pow,1000000007))%1000000007
print(ans)