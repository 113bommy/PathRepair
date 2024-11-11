def comp(A):
    for i in range(n-2, -1, -1):
        for j in range(m-2, -1, -1):
            if (A[i+1][j+1] <= A[i][j+1] or A[i+1][j+1] <= A[i+1][j]):
                return -1
            if (A[i][j] == 0):
                A[i][j] = min (A[i+1][j]-1, A[i][j+1]-1)
                if (A[i][j] <= A[i-1][j] or A[i][j] <= A[i][j-1] or A[i][j] == 0):
                    return -1
    
    return sum([sum(A[i]) for i in range(n)])
 
n, m = map(int, input().rstrip().split())
 
A = []
for i in range(n):
    A.append(list(map(int, input().rstrip().split())))
res = comp (A)
 
print(res)