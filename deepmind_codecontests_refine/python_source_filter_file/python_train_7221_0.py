matrix=[]
for i in range(5):
    l=list(map(int,input().split()))
    matrix.append(l)
for j in range(5):
    for k in range(5):
        if(matrix[j][k]==1):
            print(abs(j-3)+abs(k-3))
            break