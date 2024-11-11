mat=[]
for i in range(int(input())):
    a=list(map(int,input().split()))
    mat.append(a)
mat.sort()
best=-1
for i in range(len(mat)):
    if(mat[i][1]>=best):
        best=mat[i][1]
    else:
        best=mat[i][0]
print(best)
    