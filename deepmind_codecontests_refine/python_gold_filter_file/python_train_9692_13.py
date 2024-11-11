n,m = input().split()
n = int(n)
m = int(m)
matrix = []
for x in range(n):
    matrix = matrix + [input()]
#print(matrix)
a = 0
b = 0
count = 0
while a < n:
    b = 0
    while b < m:
        if matrix[a][b] == 'B':
            break
        if matrix[a][b] != 'B':
            count = count + 1
        b = b+1
    if b<m:
        if matrix[a][b] == 'B':
                break
    a = a+1
ib = b
while b<m:
    if matrix[a][b] == 'W':
        break
    b = b+1
fb = b
#print(ib,fb)
k = (fb-ib)//2 +1
if count==m*n:
    print(0,0)
else:
    print(a+k,ib+k)

