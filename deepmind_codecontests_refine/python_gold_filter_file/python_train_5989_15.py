
n= int(input())
matrix = [ [ 'c' for i in range(n) ] for j in range(n)]

for i in range(n):
    matrix[i]=list(input())


#print(matrix)
ans=0
for i in range(n):
    count=0
    for j in range(n):
        if matrix[i][j]=='C':
            count=count+1
    ans=ans+(count*(count-1))/2
for i in range(n):
    count=0
    for j in range(n):
        if matrix[j][i]=='C':
            count=count+1
    ans=ans+(count*(count-1))/2

print(int(ans))
