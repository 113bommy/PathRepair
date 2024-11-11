n = int(input())
matrix = list()
for i in range(n):
    temp = input()
    l = list()
    for j in temp:
        l.append(j)
    matrix.append(l)
if n<3:
    print(0)
else:
    count = 0
    for i in range(1,n-1):
        for j in range(1,n-1):
            if(matrix[i][j]=="X" and matrix[i-1][j-1]=="X" and matrix[i-1][j+1]=="X" and matrix[i+1][j-1]=="X" and matrix[i+1][j+1]=="X" ):
                count+=1
    print(count)