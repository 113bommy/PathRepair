n = int(input())

t = []
for i in range(n):
    e = list(map(int,input().split()))
    t.append(e)

size = 0
size2 = 0
for i in t:
    size += i[0]
    size2 += i[1]

matrix = [[-1000]*(size+1) for i in range(n)]
for i in range(n):
    matrix[i][0] = 0

for i in range(n):
    for j in range(1,size+1):
        if t[i][0] <= j:
            matrix[i][j] = max(matrix[i-1][j],matrix[i-1][j-t[i][0]] + t[i][1])
        else:
            matrix[i][j] = matrix[i-1][j]
    print(matrix[i])

for i in range(1,size+1):
    if i >= size2 - matrix[-1][i]:
        print(i) 
        break