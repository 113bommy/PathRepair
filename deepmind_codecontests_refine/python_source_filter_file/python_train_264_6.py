mat = []
for i in range(4):
    l = list(map(str,input()))
    mat.append(l)
diag1 = mat[0][0]+mat[1][1]+mat[2][2]
diag2 = mat[1][0]+mat[2][1]+mat[3][2]
diag3 = mat[0][1]+mat[1][2]+mat[2][3]
diag4 = mat[0][2]+mat[1][1]+mat[2][0]
diag4 = mat[0][3]+mat[1][2]+mat[2][1]
diag5 = mat[1][3]+mat[2][2]+mat[3][2]
diag6 = mat[3][0]+mat[2][1]+mat[1][2]
diag7 = mat[3][1]+mat[2][2]+mat[1][3]
diag8 = mat[1][3]+mat[2][2]+mat[3][2]
diag9 = mat[2][0]+mat[1][1]+mat[0][2]
diag10 = mat[3][3]+mat[2][2]+mat[1][1]
diag11 = mat[2][3]+mat[1][2]+mat[0][1]
diag12 = mat[3][2]+mat[2][1]+mat[1][0]
l = [diag1,diag2,diag3,diag4,diag5,diag6,diag7,diag8,diag9,diag10,diag11,diag12]
if 'x.x' in l or 'xx.' in l or '.xx' in l:
    print("YES")

else:
    for i in range(4):
        for j in range(2):
            row = mat[i][j]+mat[i][j+1]+mat[i][j+2]
            if row=='x.x' or row=='xx.' or row=='.xx':
                print("YES")
                exit()
    for i in range(4):
        for j in range(2):
            row = mat[j][i]+mat[j+1][i]+mat[j+2][i]
            if row=='x.x' or row=='xx.' or row=='.xx':
                print("YES")
                exit()
    print("NO")
    exit()