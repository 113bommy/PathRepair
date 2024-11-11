def isCross(a, matrix):
    n = len(matrix)
    i,j = a
    for x,y in [ (i-1,j), (i-1,j-1), (i+1,j+1), (i,j-1) ]:
        if matrix[x][y] != 'X':
            return False
    return True

n = int(input())
matrix = [ input() for _ in range(n) ]
cnt = 0
for i in range(1,n-1):
    for j in range(1,n-1):
        if matrix[i][j]=='X' and isCross((i,j), matrix):
            cnt+=1
print(cnt)