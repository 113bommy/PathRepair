n=int(input())
matrix = [[0 for x in range (101)] for y in range(n)] 
for i in range(n):
    m=list(map(int,input().split(' ')))
    for j in range(1,len(m)):
        matrix[i][m[j]]=1


for i in range(n):
    ans='YES'
    for j in range(n):
        if i==j:
            continue
        for k in range(101):
            if matrix[i][k]==0 and matrix[j][k]==1:
                break
            
        
        if k==len(matrix[0])-1:
            ans='NO'

    print(ans)
