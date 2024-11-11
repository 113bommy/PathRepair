floor,flats = map(int,input().split())

matrix = []
for i in range(floor):
    matrix.append(list(map(int,input().split())))

count = 0
for i in range(floor):
    for j in range(flats):
        if matrix[i][2*j] == 0 or matrix[i][2*j+1] == 0:
            count += 1 
print(count)